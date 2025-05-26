$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/screen_capture_kit_device_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/media/capture/screen_capture_kit_device_mac.mm
@@ -26,6 +26,61 @@ using SampleCallback = base::RepeatingCa
                                                     std::optional<gfx::Rect>,
                                                     bool)>;
 using ErrorCallback = base::RepeatingClosure;
+using CancelCallback = base::RepeatingClosure;
+
+API_AVAILABLE(macos(15.0))
+@interface ScreenCaptureKitPickerHelper
+    : NSObject <SCContentSharingPickerObserver>
+
+- (void)contentSharingPicker:(SCContentSharingPicker *)picker
+          didCancelForStream:(SCStream *)stream;
+
+- (void)contentSharingPicker:(SCContentSharingPicker *)picker
+         didUpdateWithFilter:(SCContentFilter *)filter
+                   forStream:(SCStream *)stream;
+
+- (void)contentSharingPickerStartDidFailWithError:(NSError *)error;
+
+@end
+
+@implementation ScreenCaptureKitPickerHelper {
+  base::RepeatingCallback<void(SCContentFilter *)> _pickerCallback;
+  ErrorCallback _errorCallback;
+  CancelCallback _cancelCallback;
+}
+
+- (void)contentSharingPicker:(SCContentSharingPicker *)picker
+          didCancelForStream:(SCStream *)stream {
+  // TODO: This doesn't appear to be called on Apple's side;
+  // implement this logic
+  _cancelCallback.Run();
+}
+
+- (void)contentSharingPicker:(SCContentSharingPicker *)picker
+         didUpdateWithFilter:(SCContentFilter *)filter
+                   forStream:(SCStream *)stream {
+  if (stream == nil) {
+    _pickerCallback.Run(filter);
+    [picker removeObserver:self];
+  }
+}
+
+- (void)contentSharingPickerStartDidFailWithError:(NSError *)error {
+  _errorCallback.Run();
+}
+
+- (instancetype)initWithStreamPickCallback:(base::RepeatingCallback<void(SCContentFilter *)>)pickerCallback
+                             cancelCallback:(CancelCallback)cancelCallback
+                             errorCallback:(ErrorCallback)errorCallback {
+  if (self = [super init]) {
+    _pickerCallback = pickerCallback;
+    _cancelCallback = cancelCallback;
+    _errorCallback = errorCallback;
+  }
+  return self;
+}
+
+@end
 
 namespace {
 API_AVAILABLE(macos(12.3))
@@ -100,18 +155,22 @@ API_AVAILABLE(macos(12.3))
     : NSObject <SCStreamDelegate, SCStreamOutput>
 
 - (instancetype)initWithSampleCallback:(SampleCallback)sampleCallback
+                         cancelCallback:(CancelCallback)cancelCallback
                          errorCallback:(ErrorCallback)errorCallback;
 @end
 
 @implementation ScreenCaptureKitDeviceHelper {
   SampleCallback _sampleCallback;
+  CancelCallback _cancelCallback;
   ErrorCallback _errorCallback;
 }
 
 - (instancetype)initWithSampleCallback:(SampleCallback)sampleCallback
+                         cancelCallback:(CancelCallback)cancelCallback
                          errorCallback:(ErrorCallback)errorCallback {
   if (self = [super init]) {
     _sampleCallback = sampleCallback;
+    _cancelCallback = cancelCallback;
     _errorCallback = errorCallback;
   }
   return self;
@@ -187,7 +246,8 @@ BASE_FEATURE(kScreenCaptureKitFullDeskto
 
 class API_AVAILABLE(macos(12.3)) ScreenCaptureKitDeviceMac
     : public IOSurfaceCaptureDeviceBase,
-      public ScreenCaptureKitResetStreamInterface {
+      public ScreenCaptureKitResetStreamInterface
+       {
  public:
   explicit ScreenCaptureKitDeviceMac(const DesktopMediaID& source,
                                      SCContentFilter* filter)
@@ -198,18 +258,42 @@ class API_AVAILABLE(macos(12.3)) ScreenC
         device_task_runner_,
         base::BindRepeating(&ScreenCaptureKitDeviceMac::OnStreamSample,
                             weak_factory_.GetWeakPtr()));
+    CancelCallback cancel_callback = base::BindPostTask(
+        device_task_runner_,
+        base::BindRepeating(&ScreenCaptureKitDeviceMac::OnStreamError,
+                            weak_factory_.GetWeakPtr()));
     ErrorCallback error_callback = base::BindPostTask(
         device_task_runner_,
         base::BindRepeating(&ScreenCaptureKitDeviceMac::OnStreamError,
                             weak_factory_.GetWeakPtr()));
     helper_ = [[ScreenCaptureKitDeviceHelper alloc]
         initWithSampleCallback:sample_callback
+                 cancelCallback:cancel_callback
                  errorCallback:error_callback];
+
+    if (@available(macOS 15.0, *)) {
+      auto picker_callback = base::BindPostTask(
+        device_task_runner_,
+        base::BindRepeating(&ScreenCaptureKitDeviceMac::OnContentFilterReady, weak_factory_.GetWeakPtr())
+      );
+      picker_helper_ = [[ScreenCaptureKitPickerHelper alloc] initWithStreamPickCallback:picker_callback cancelCallback:cancel_callback errorCallback:error_callback];
+      [[SCContentSharingPicker sharedPicker] addObserver:picker_helper_];
+    }
   }
   ScreenCaptureKitDeviceMac(const ScreenCaptureKitDeviceMac&) = delete;
   ScreenCaptureKitDeviceMac& operator=(const ScreenCaptureKitDeviceMac&) =
       delete;
-  ~ScreenCaptureKitDeviceMac() override = default;
+  ~ScreenCaptureKitDeviceMac() override {
+    if (@available(macOS 15.0, *)) {
+      auto* picker = [SCContentSharingPicker sharedPicker];
+      ScreenCaptureKitDeviceMac::active_streams_--;
+      picker.maximumStreamCount = @(ScreenCaptureKitDeviceMac::active_streams_);
+      if (ScreenCaptureKitDeviceMac::active_streams_ == 0 && picker.active) {
+        picker.active = false;
+        [[SCContentSharingPicker sharedPicker] removeObserver:picker_helper_];
+      }
+    }
+  }
 
   void OnShareableContentCreated(SCShareableContent* content) {
     DCHECK(device_task_runner_->RunsTasksInCurrentSequence());
@@ -230,8 +314,17 @@ class API_AVAILABLE(macos(12.3)) ScreenC
           // fallback. See https://crbug.com/325530044.
           if (source_.id == display.displayID ||
               source_.id == webrtc::kFullDesktopScreenId) {
+            NSArray<NSWindow*>* exclude_ns_windows = [[[NSApplication sharedApplication] windows] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSWindow* win, NSDictionary *bindings) {
+              return [win sharingType] == NSWindowSharingNone;
+            }]];
+            NSArray<SCWindow*>* exclude_windows = [[content windows] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(SCWindow* win, NSDictionary *bindings) {
+              for (NSWindow* excluded : exclude_ns_windows) {
+                if ((CGWindowID)[excluded windowNumber] == [win windowID]) return true;
+              }
+              return false;
+            }]];
             filter = [[SCContentFilter alloc] initWithDisplay:display
-                                             excludingWindows:@[]];
+                                             excludingWindows:exclude_windows];
             stream_config_content_size_ =
                 gfx::Size(display.width, display.height);
             break;
@@ -268,7 +361,7 @@ class API_AVAILABLE(macos(12.3)) ScreenC
       return;
     }
 
-    if (@available(macOS 14.0, *)) {
+    if (@available(macOS 15.0, *)) {
       // Update the content size. This step is neccessary when used together
       // with SCContentSharingPicker. If the Chrome picker is used, it will
       // change to retina resolution if applicable.
@@ -277,6 +370,9 @@ class API_AVAILABLE(macos(12.3)) ScreenC
                     filter.contentRect.size.height * filter.pointPixelScale);
     }
 
+    OnContentFilterReady(filter);
+  }
+  void OnContentFilterReady(SCContentFilter* filter) {
     gfx::RectF dest_rect_in_frame;
     actual_capture_format_ = capture_params().requested_format;
     actual_capture_format_.pixel_format = media::PIXEL_FORMAT_NV12;
@@ -290,6 +386,7 @@ class API_AVAILABLE(macos(12.3)) ScreenC
     stream_ = [[SCStream alloc] initWithFilter:filter
                                  configuration:config
                                       delegate:helper_];
+
     {
       NSError* error = nil;
       bool add_stream_output_result =
@@ -443,7 +540,7 @@ class API_AVAILABLE(macos(12.3)) ScreenC
       if (fullscreen_module_) {
         fullscreen_module_->Reset();
       }
-      OnStart();
+      OnStart(std::nullopt);
     } else {
       client()->OnError(media::VideoCaptureError::kScreenCaptureKitStreamError,
                         FROM_HERE, "Stream delegate called didStopWithError");
@@ -466,23 +563,41 @@ class API_AVAILABLE(macos(12.3)) ScreenC
   }
 
   // IOSurfaceCaptureDeviceBase:
-  void OnStart() override {
+  void OnStart(std::optional<bool> use_native_picker) override {
     DCHECK(device_task_runner_->RunsTasksInCurrentSequence());
-    if (filter_) {
-      // SCContentSharingPicker is used where filter_ is set on creation.
-      CreateStream(filter_);
-    } else {
-      // Chrome picker is used.
-      auto content_callback = base::BindPostTask(
-          device_task_runner_,
-          base::BindRepeating(
-              &ScreenCaptureKitDeviceMac::OnShareableContentCreated,
-              weak_factory_.GetWeakPtr()));
-      auto handler = ^(SCShareableContent* content, NSError* error) {
-        content_callback.Run(content);
-      };
-      [SCShareableContent getShareableContentWithCompletionHandler:handler];
+
+    if (@available(macOS 15.0, *)) {
+      constexpr bool DefaultUseNativePicker = true;
+      if (use_native_picker.value_or(DefaultUseNativePicker) &&
+          source_.id == DesktopMediaID::kMacOsNativePickerId &&
+          source_.window_id < 0) {
+        auto* picker = [SCContentSharingPicker sharedPicker];
+        ScreenCaptureKitDeviceMac::active_streams_++;
+        picker.maximumStreamCount = @(ScreenCaptureKitDeviceMac::active_streams_);
+        if (!picker.active) {
+          picker.active = true;
+        }
+        NSMutableArray<NSNumber*>* exclude_ns_windows = [NSMutableArray array];
+        [[[[NSApplication sharedApplication] windows] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSWindow* win, NSDictionary *bindings) {
+          return [win sharingType] == NSWindowSharingNone;
+        }]] enumerateObjectsUsingBlock:^(NSWindow* win, NSUInteger idx, BOOL *stop) {
+          [exclude_ns_windows addObject:@([win windowNumber])];
+        }];
+        picker.defaultConfiguration.excludedWindowIDs = exclude_ns_windows;
+        [picker present];
+        return;
+      }
     }
+
+    auto content_callback = base::BindPostTask(
+        device_task_runner_,
+        base::BindRepeating(
+            &ScreenCaptureKitDeviceMac::OnShareableContentCreated,
+            weak_factory_.GetWeakPtr()));
+    auto handler = ^(SCShareableContent* content, NSError* error) {
+      content_callback.Run(content);
+    };
+    [SCShareableContent getShareableContentWithCompletionHandler:handler];
   }
   void OnStop() override {
     DCHECK(device_task_runner_->RunsTasksInCurrentSequence());
@@ -540,6 +655,8 @@ class API_AVAILABLE(macos(12.3)) ScreenC
   }
 
  private:
+  static int active_streams_;
+
   const DesktopMediaID source_;
   SCContentFilter* const filter_;
   const scoped_refptr<base::SingleThreadTaskRunner> device_task_runner_;
@@ -557,6 +674,10 @@ class API_AVAILABLE(macos(12.3)) ScreenC
   // Helper class that acts as output and delegate for `stream_`.
   ScreenCaptureKitDeviceHelper* __strong helper_;
 
+  // Helper class that acts as an observer for SCContentSharingPicker
+  API_AVAILABLE(macos(15.0))
+  ScreenCaptureKitPickerHelper* __strong picker_helper_;
+
   // This is used to detect when a captured presentation enters fullscreen mode.
   // If this happens, the module will call the ResetStreamTo function.
   std::unique_ptr<ScreenCaptureKitFullscreenModule> fullscreen_module_;
@@ -569,6 +690,8 @@ class API_AVAILABLE(macos(12.3)) ScreenC
   base::WeakPtrFactory<ScreenCaptureKitDeviceMac> weak_factory_{this};
 };
 
+int ScreenCaptureKitDeviceMac::active_streams_ = 0;
+
 }  // namespace
 
 // Although ScreenCaptureKit is available in 12.3 there were some bugs that
