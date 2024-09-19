$NetBSD$

--- src/VBox/Main/include/USBProxyService.h.orig	2016-03-04 19:29:37.000000000 +0000
+++ src/VBox/Main/include/USBProxyService.h
@@ -347,7 +347,7 @@ private:
 };
 # endif /* RT_OS_WINDOWS */
 
-# ifdef RT_OS_FREEBSD
+# ifdef defined(RT_OS_FREEBSD)
 /**
  * The FreeBSD hosted USB Proxy Service.
  */
@@ -376,5 +376,34 @@ private:
 };
 # endif /* RT_OS_FREEBSD */
 
+# ifdef defined(RT_OS_NETBSD)
+/**
+ * The NetBSD hosted USB Proxy Service.
+ */
+class USBProxyServiceNetBSD : public USBProxyService
+{
+public:
+    USBProxyServiceNetBSD(Host *aHost);
+    HRESULT init(void);
+    ~USBProxyServiceNetBSD();
+
+    virtual int captureDevice(HostUSBDevice *aDevice);
+    virtual int releaseDevice(HostUSBDevice *aDevice);
+
+protected:
+    int initUsbfs(void);
+    int initSysfs(void);
+    virtual int wait(RTMSINTERVAL aMillies);
+    virtual int interruptWait(void);
+    virtual PUSBDEVICE getDevices(void);
+    int addDeviceToChain(PUSBDEVICE pDev, PUSBDEVICE *ppFirst, PUSBDEVICE **pppNext, int rc);
+    virtual void deviceAdded(ComObjPtr<HostUSBDevice> &aDevice, SessionMachinesList &llOpenedMachines, PUSBDEVICE aUSBDevice);
+    virtual bool updateDeviceState(HostUSBDevice *aDevice, PUSBDEVICE aUSBDevice, bool *aRunFilters, SessionMachine **aIgnoreMachine);
+
+private:
+    RTSEMEVENT mNotifyEventSem;
+};
+# endif /* RT_OS_NETBSD */
+
 #endif /* !____H_USBPROXYSERVICE */
 /* vi: set tabstop=4 shiftwidth=4 expandtab: */
