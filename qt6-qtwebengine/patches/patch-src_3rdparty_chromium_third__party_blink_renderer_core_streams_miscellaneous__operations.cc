$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/streams/miscellaneous_operations.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/streams/miscellaneous_operations.cc
@@ -504,7 +504,7 @@ CORE_EXPORT double ValidateAndNormalizeH
   // https://streams.spec.whatwg.org/#validate-and-normalize-high-water-mark
   // 2. If highWaterMark is NaN or highWaterMark < 0, throw a RangeError
   //    exception.
-  if (isnan(high_water_mark) || high_water_mark < 0) {
+  if (std::isnan(high_water_mark) || high_water_mark < 0) {
     exception_state.ThrowRangeError(
         "A queuing strategy's highWaterMark property must be a nonnegative, "
         "non-NaN number");
