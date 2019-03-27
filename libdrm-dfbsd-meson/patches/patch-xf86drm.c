$NetBSD: patch-xf86drm.c,v 1.4 2019/01/22 21:50:47 wiz Exp $

Implement drmParseSubsystemType, drmParsePciBusInfo for NetBSD

Patches from FreeBSD ports / DragonFly dports for graphics/libdrm 2.4.84.

--- xf86drm.c.orig	2019-03-12 11:55:31.000000000 +0000
+++ xf86drm.c
@@ -46,6 +46,11 @@
 #include <signal.h>
 #include <time.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
+#endif
 #include <sys/stat.h>
 #define stat_t struct stat
 #include <sys/ioctl.h>
@@ -59,6 +64,10 @@
 #endif
 #include <math.h>
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <sys/pciio.h>
+#endif
+
 #define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
 
 /* Not all systems have MAP_FAILED defined */
@@ -82,11 +91,23 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#define DRM_MAJOR 0	/* Major ID unused on systems with devfs */
+#endif
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#define DRM_NODE_NAME_MAX                   \
+    (sizeof(DRM_DIR_NAME) +                 \
+     MAX3(sizeof(DRM_PRIMARY_MINOR_NAME),   \
+         sizeof(DRM_CONTROL_MINOR_NAME),    \
+         sizeof(DRM_RENDER_MINOR_NAME))     \
+    + 3) /* length of the node number */
 #endif
 
 #ifdef __NetBSD__
-#define DRM_MAJOR 34
+#define DRM_MAJOR 180
+#include <sys/param.h>
+#include <dev/pci/pcireg.h>
+#include <pci.h>
 #endif
 
 #ifdef __OpenBSD__
@@ -101,7 +122,7 @@
 #define DRM_MAJOR 226 /* Linux */
 #endif
 
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__)
 struct drm_pciinfo {
 	uint16_t	domain;
 	uint8_t		bus;
@@ -222,6 +243,35 @@ drm_public drmHashEntry *drmGetEntry(int
     return entry;
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+static int drmGetMinorBase(int type);
+static int drmGetMinorType(int minor);
+
+static const char *drmGetDeviceName(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+            return DRM_DEV_NAME;
+        case DRM_NODE_CONTROL:
+            return DRM_CONTROL_DEV_NAME;
+        case DRM_NODE_RENDER:
+            return DRM_RENDER_DEV_NAME;
+        default:
+            return NULL;
+    }
+}
+
+static int drmGetNodeNumber(const char *name)
+{
+    size_t name_len = strnlen(name, DRM_NODE_NAME_MAX);
+    while (name_len && isdigit(name[name_len - 1]))
+        --name_len;
+    return strtol(name + name_len, NULL, 10);
+}
+
+static int drmGetNodeType(const char *name);
+#endif /* __FreeBSD__ || __DragonFly__ */
+
 /**
  * Compare two busid strings
  *
@@ -351,7 +401,11 @@ static int drmOpenDevice(dev_t dev, int 
         return -EINVAL;
     };
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     drmMsg("drmOpenDevice: node name is %s\n", buf);
 
     if (drm_server_info && drm_server_info->get_perms) {
@@ -475,7 +529,11 @@ static int drmOpenMinor(int minor, int c
         return -EINVAL;
     };
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     if ((fd = open(buf, O_RDWR | O_CLOEXEC, 0)) >= 0)
         return fd;
     return -errno;
@@ -519,12 +577,19 @@ drm_public int drmAvailable(void)
 static int drmGetMinorBase(int type)
 {
     switch (type) {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type << 6;
+#else /* !__FreeBSD__ && !__DragonFly__ */
     case DRM_NODE_PRIMARY:
         return 0;
     case DRM_NODE_CONTROL:
         return 64;
     case DRM_NODE_RENDER:
         return 128;
+#endif /* __FreeBSD__ || __DragonFly__ */
     default:
         return -1;
     };
@@ -547,6 +612,7 @@ static int drmGetMinorType(int minor)
     }
 }
 
+#ifdef __linux__
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -560,6 +626,7 @@ static const char *drmGetMinorName(int t
         return NULL;
     }
 }
+#endif /* __linux__ */
 
 /**
  * Open the device by bus ID.
@@ -2594,7 +2661,7 @@ drm_public int drmCommandNone(int fd, un
 {
     unsigned long request;
 
-    request = DRM_IO( DRM_COMMAND_BASE + drmCommandIndex);
+    request = DRM_IO( (DRM_COMMAND_BASE + drmCommandIndex) );
 
     if (drmIoctl(fd, request, NULL)) {
         return -errno;
@@ -2820,12 +2887,29 @@ static bool drmNodeIsDRM(int maj, int mi
              maj, min);
     return stat(path, &sbuf) == 0;
 #else
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    return !DRM_MAJOR || maj == DRM_MAJOR;
+#else
     return maj == DRM_MAJOR;
 #endif
+#endif
 }
 
 drm_public int drmGetNodeTypeFromFd(int fd)
 {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name) {
+        errno = ENODEV;
+        return -1;
+    }
+
+    int type = drmGetNodeType(name);
+    free(name);
+    if (type < 0)
+        errno = ENODEV;
+    return type;
+#else
     struct stat sbuf;
     int maj, min, type;
 
@@ -2844,6 +2928,7 @@ drm_public int drmGetNodeTypeFromFd(int 
     if (type == -1)
         errno = ENODEV;
     return type;
+#endif
 }
 
 drm_public int drmPrimeHandleToFD(int fd, uint32_t handle, uint32_t flags,
@@ -2922,6 +3007,25 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    const char *dev_name = drmGetDeviceName(type);
+    if (!dev_name)
+        return NULL;
+
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name)
+        return NULL;
+
+    int oldnum = drmGetNodeNumber(name);
+    int oldtype = drmGetMinorType(oldnum);
+    if (oldtype < 0) {
+        free(name);
+        return NULL;
+    }
+
+    int newnum = oldnum - drmGetMinorBase(oldtype) + drmGetMinorBase(type);
+    snprintf(name, DRM_NODE_NAME_MAX, dev_name, DRM_DIR_NAME, newnum);
+    return name;
 #else
     struct stat sbuf;
     char buf[PATH_MAX + 1];
@@ -2957,7 +3061,7 @@ static char *drmGetMinorNameForFD(int fd
         return NULL;
 
     n = snprintf(buf, sizeof(buf), dev_name, DRM_DIR_NAME, min - base);
-    if (n == -1 || n >= sizeof(buf))
+    if (n == -1 || n >= (int)sizeof(buf))
         return NULL;
 
     return strdup(buf);
@@ -3055,7 +3159,66 @@ static int drmParseSubsystemType(int maj
     }
 
     return -EINVAL;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+	    /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+    }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Find a string we know about; otherwise -EINVAL.  */
+    ret = -EINVAL;
+    if (strncmp(buf, "pci:", 4) == 0)
+	ret = DRM_BUS_PCI;
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* Success or not, we're done.  */
+    return ret;
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -3063,6 +3226,7 @@ static int drmParseSubsystemType(int maj
 #endif
 }
 
+#ifdef __linux__
 static void
 get_pci_path(int maj, int min, char *pci_path)
 {
@@ -3078,8 +3242,14 @@ get_pci_path(int maj, int min, char *pci
     if (term && strncmp(term, "/virtio", 7) == 0)
         *term = 0;
 }
+#endif
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+static int drmParsePciBusInfo(const char *node, int node_type,
+                              int maj, int min, drmPciBusInfoPtr info)
+#else
 static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
+#endif
 {
 #ifdef __linux__
     unsigned int domain, bus, dev, func;
@@ -3104,7 +3274,74 @@ static int drmParsePciBusInfo(int maj, i
     info->func = func;
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+            /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+    }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Parse the bus id.  */
+    ret = sscanf(buf, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev, &func);
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* If scanf didn't return 4 -- domain, bus, dev, func -- then fail.  */
+    if (ret != 4)
+	return -ENODEV;
+
+    /* Populate the results.  */
+    info->domain = domain;
+    info->bus = bus;
+    info->dev = dev;
+    info->func = func;
+
+    /* Success!  */
+    return 0;
+#elif defined(__OpenBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3128,6 +3365,61 @@ static int drmParsePciBusInfo(int maj, i
     info->func = pinfo.func;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    /*
+     * Only the primary nodes can be mapped to hw.dri.%i via major/minor
+     * Determine the primary node by offset and use its major/minor pair
+     */
+    if (node_type != DRM_NODE_PRIMARY) {
+        char name[DRM_NODE_NAME_MAX];
+        snprintf(name, sizeof(name), DRM_DEV_NAME, DRM_DIR_NAME,
+                 drmGetNodeNumber(node) - drmGetMinorBase(node_type));
+
+        stat_t sbuf;
+        if (stat(name, &sbuf))
+            return -errno;
+
+        maj = major(sbuf.st_rdev);
+        min = minor(sbuf.st_rdev);
+
+    }
+    /*
+     * Major/minor appear after the driver name in the hw.dri.%i.name node
+     * Find the node with matching major/minor pair and parse the bus ID,
+     * which may be after the name or may be alone in hw.dri.%i.busid
+     */
+    #define bus_fmt "pci:%04x:%02x:%02x.%u"
+    #define name_fmt "%*s %x " bus_fmt
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char name[16], value[256];
+        size_t length = sizeof(value);
+        snprintf(name, sizeof(name), "hw.dri.%i.name", i);
+        if (sysctlbyname(name, value, &length, NULL, 0))
+            continue;
+
+        value[length] = '\0';
+        unsigned int rdev = 0, domain = 0, bus = 0, slot = 0, func = 0;
+        int vals = sscanf(value, name_fmt, &rdev, &domain, &bus, &slot, &func);
+
+	if (vals >= 1 && rdev == makedev(maj,min)) {
+            if (vals < 5) {
+                /* busid not in the name, try busid */
+                length = sizeof(value);
+                snprintf(name, sizeof(name), "hw.dri.%i.busid", i);
+                if (sysctlbyname(name, value, &length, NULL, 0))
+                    break;
+                value[length] = '\0';
+                if (sscanf(value, bus_fmt, &domain, &bus, &slot, &func) != 4)
+                    break;
+            }
+            info->domain = domain;
+            info->bus = bus;
+            info->dev = slot;
+            info->func = func;
+            return 0;
+        }
+    }
+    return -ENODEV;
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
     return -EINVAL;
@@ -3176,7 +3468,11 @@ static int drmGetNodeType(const char *na
         sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
         return DRM_NODE_RENDER;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    return -1;
+#else /* !__FreeBSD__ || __DragonFly__ */
     return -EINVAL;
+#endif /* __FreeBSD__ || __DragonFly__ */
 }
 
 static int drmGetMaxNodeName(void)
@@ -3259,6 +3555,9 @@ static int parse_config_sysfs_file(int m
 #endif
 
 static int drmParsePciDeviceInfo(int maj, int min,
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+                                 drmPciBusInfoPtr info,
+#endif
                                  drmPciDeviceInfoPtr device,
                                  uint32_t flags)
 {
@@ -3270,7 +3569,49 @@ static int drmParsePciDeviceInfo(int maj
         return parse_config_sysfs_file(maj, min, device);
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__)
+    drmPciBusInfo businfo;
+    char fname[PATH_MAX];
+    int pcifd;
+    pcireg_t id, class, subsys;
+    int ret;
+
+    /* Find where on the bus the device lives.  */
+    ret = drmParsePciBusInfo(maj, min, &businfo);
+    if (ret)
+	return ret;
+
+    /* Open the pciN device node to get at its config registers.  */
+    if (snprintf(fname, sizeof fname, "/dev/pci%u", businfo.domain)
+	>= sizeof fname)
+	return -ENODEV;
+    if ((pcifd = open(fname, O_RDONLY)) == -1)
+	return -errno;
+
+    ret = -1;
+    /* Read the id and class pci config registers.  */
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_ID_REG, &id) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_CLASS_REG, &class) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_SUBSYS_ID_REG, &subsys) == -1)
+	goto out;
+
+    ret = 0;
+    device->vendor_id = PCI_VENDOR(id);
+    device->device_id = PCI_PRODUCT(id);
+    device->subvendor_id = PCI_SUBSYS_VENDOR(subsys);
+    device->subdevice_id = PCI_SUBSYS_ID(subsys);
+    device->revision_id = PCI_REVISION(class);
+out:
+    if (ret == -1)
+	ret = -errno;
+    close(pcifd);
+    return ret;
+#elif defined(__OpenBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3295,6 +3636,43 @@ static int drmParsePciDeviceInfo(int maj
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    struct pci_conf_io pc;
+    struct pci_match_conf patterns[1];
+    struct pci_conf results[1];
+
+    int fd = open("/dev/pci", O_RDONLY, 0);
+    if (fd < 0)
+        return -errno;
+
+    bzero(&patterns, sizeof(patterns));
+    patterns[0].pc_sel.pc_domain = info->domain;
+    patterns[0].pc_sel.pc_bus = info->bus;
+    patterns[0].pc_sel.pc_dev = info->dev;
+    patterns[0].pc_sel.pc_func = info->func;
+    patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
+                      | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
+    bzero(&pc, sizeof(struct pci_conf_io));
+    pc.num_patterns = 1;
+    pc.pat_buf_len = sizeof(patterns);
+    pc.patterns = patterns;
+    pc.match_buf_len = sizeof(results);
+    pc.matches = results;
+
+    if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
+        int error = errno;
+        close(fd);
+        return -error;
+    }
+    close(fd);
+
+    device->vendor_id = results[0].pc_vendor;
+    device->device_id = results[0].pc_device;
+    device->subvendor_id = results[0].pc_subvendor;
+    device->subdevice_id = results[0].pc_subdevice;
+    device->revision_id = results[0].pc_revid;
+
+    return 0;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
@@ -3421,18 +3799,42 @@ static int drmProcessPciDevice(drmDevice
 
     dev->businfo.pci = (drmPciBusInfoPtr)addr;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    ret = drmParsePciBusInfo(node, node_type, maj, min, dev->businfo.pci);
+#else
     ret = drmParsePciBusInfo(maj, min, dev->businfo.pci);
+#endif
     if (ret)
         goto free_device;
 
+    drmMsg("[drm] drmProcessPciDevice: DOMAIN    (%04x)\n", dev->businfo.pci->domain);
+    drmMsg("[drm] drmProcessPciDevice: BUS       (%02x)\n", dev->businfo.pci->bus);
+    drmMsg("[drm] drmProcessPciDevice: DEV       (%02x)\n", dev->businfo.pci->dev);
+    drmMsg("[drm] drmProcessPciDevice: FUNC      (%1u)\n",  dev->businfo.pci->func);
+
     // Fetch the device info if the user has requested it
     if (fetch_deviceinfo) {
         addr += sizeof(drmPciBusInfo);
         dev->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        ret = drmParsePciDeviceInfo(maj, min, dev->businfo.pci, dev->deviceinfo.pci, flags);
+#else
         ret = drmParsePciDeviceInfo(maj, min, dev->deviceinfo.pci, flags);
+#endif
         if (ret)
             goto free_device;
+
+        drmMsg("[drm] drmProcessPciDevice: VENDOR    (%04x)\n",
+            dev->deviceinfo.pci->vendor_id);
+        drmMsg("[drm] drmProcessPciDevice: DEVICE    (%04x)\n",
+            dev->deviceinfo.pci->device_id);
+        drmMsg("[drm] drmProcessPciDevice: SUBVENDOR (%04x)\n",
+            dev->deviceinfo.pci->subvendor_id);
+        drmMsg("[drm] drmProcessPciDevice: SUBDEVICE (%04x)\n",
+            dev->deviceinfo.pci->subdevice_id);
+        drmMsg("[drm] drmProcessPciDevice: REVISION  (%02x)\n",
+            dev->deviceinfo.pci->revision_id);
     }
 
     *device = dev;
@@ -4101,6 +4503,23 @@ drm_public char *drmGetDeviceNameFromFd2
     free(value);
 
     return strdup(path);
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    stat_t sbuf;
+    if (fstat(fd, &sbuf))
+        return NULL;
+
+    dev_t rdev = sbuf.st_rdev;
+    /* minor numbers don't depend on node name suffix, search for a match */
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char node[DRM_NODE_NAME_MAX];
+        for (int j = 0; j < DRM_NODE_MAX; ++j) {
+            snprintf(node, sizeof(node), drmGetDeviceName(j),
+                     DRM_DIR_NAME, drmGetMinorBase(j) + i);
+            if (stat(node, &sbuf) == 0 && sbuf.st_rdev == rdev)
+                return strdup(node);
+        }
+    }
+    return NULL;
 #else
     struct stat      sbuf;
     char             node[PATH_MAX + 1];
