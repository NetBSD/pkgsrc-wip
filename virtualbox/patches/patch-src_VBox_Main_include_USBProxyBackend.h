$NetBSD$

--- src/VBox/Main/include/USBProxyBackend.h.orig	2018-12-18 13:00:06.000000000 +0000
+++ src/VBox/Main/include/USBProxyBackend.h
@@ -378,6 +378,36 @@ private:
 };
 # endif /* RT_OS_FREEBSD */
 
+# if defined(RT_OS_NETBSD) || defined(DOXYGEN_RUNNING)
+/**
+ * The FreeBSD hosted USB Proxy Backend.
+ */
+class USBProxyBackendNetBSD : public USBProxyBackend
+{
+public:
+    DECLARE_EMPTY_CTOR_DTOR(USBProxyBackendNetBSD)
+
+    int init(USBProxyService *pUsbProxyService, const com::Utf8Str &strId,
+             const com::Utf8Str &strAddress, bool fLoadingSettings);
+    void uninit();
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
+
+private:
+    RTSEMEVENT mNotifyEventSem;
+};
+# endif /* RT_OS_NETBSD */
+
 /**
  * USB/IP Proxy receive state.
  */
