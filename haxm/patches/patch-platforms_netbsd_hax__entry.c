$NetBSD$

--- platforms/netbsd/hax_entry.c.orig	2018-11-24 22:22:37.787129043 +0000
+++ platforms/netbsd/hax_entry.c
@@ -0,0 +1,343 @@
+/*
+ * Copyright (c) 2018 Kamil Rytarowski
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions are met:
+ *
+ *   1. Redistributions of source code must retain the above copyright notice,
+ *      this list of conditions and the following disclaimer.
+ *
+ *   2. Redistributions in binary form must reproduce the above copyright
+ *      notice, this list of conditions and the following disclaimer in the
+ *      documentation and/or other materials provided with the distribution.
+ *
+ *   3. Neither the name of the copyright holder nor the names of its
+ *      contributors may be used to endorse or promote products derived from
+ *      this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
+ * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
+ * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
+ * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
+ * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
+ * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
+ * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
+ * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
+ * POSSIBILITY OF SUCH DAMAGE.
+ */
+
+#include <sys/param.h>
+#include <sys/conf.h>
+#include <sys/device.h>
+#include <sys/kernel.h>
+#include <sys/lwp.h>
+#include <sys/proc.h>
+#include <sys/module.h>
+#include <machine/specialreg.h>
+#include <machine/cpufunc.h>
+
+#include "../../include/hax.h"
+#include "../../include/hax_interface.h"
+#include "../../include/hax_release_ver.h"
+#include "../../core/include/hax_core_interface.h"
+
+#define HAX_DEVICE_NAME "HAX"
+
+static int hax_cmajor = 220, hax_bmajor = -1;
+
+extern struct cfdriver hax_vm_cd;
+extern struct cfdriver hax_vcpu_cd;
+extern struct cfattach hax_vm_ca;
+extern struct cfattach hax_vcpu_ca;
+
+static int hax_driver_init(void);
+static int hax_driver_exit(void);
+
+dev_type_open(hax_dev_open);
+dev_type_close(hax_dev_close);
+dev_type_ioctl(hax_dev_ioctl);
+
+static struct cdevsw hax_dev_cdevsw = {
+    .d_open = hax_dev_open,
+    .d_close = hax_dev_close,
+    .d_read = noread,
+    .d_write = nowrite,
+    .d_ioctl = hax_dev_ioctl,
+    .d_stop = nostop,
+    .d_tty = notty,
+    .d_poll = nopoll,
+    .d_mmap = nommap,
+    .d_kqfilter = nokqfilter,
+    .d_discard = nodiscard,
+    .d_flag = D_OTHER
+};
+
+int hax_dev_open(dev_t dev __unused, int flags __unused, int mode __unused,
+                    struct lwp *l __unused)
+{
+    hax_log_level(HAX_LOGI, "HAX module opened\n");
+    return 0;
+}
+
+int hax_dev_close(dev_t self __unused, int flag __unused, int mode __unused,
+                     struct lwp *l __unused)
+{
+    hax_log_level(HAX_LOGI, "hax_close\n");
+    return 0;
+}
+
+int hax_dev_ioctl(dev_t self __unused, u_long cmd, void *data, int flag,
+                         struct lwp *l)
+{
+    int ret = 0;
+
+    switch (cmd) {
+    case HAX_IOCTL_VERSION: {
+        struct hax_module_version *version;
+        version = (struct hax_module_version *)data;
+        version->cur_version = HAX_CUR_VERSION;
+        version->compat_version = HAX_COMPAT_VERSION;
+        break;
+    }
+    case HAX_IOCTL_CAPABILITY: {
+        struct hax_capabilityinfo *capab;
+        capab = (struct hax_capabilityinfo *)data;
+        hax_get_capability(capab, sizeof(*capab), NULL);
+        break;
+    }
+    case HAX_IOCTL_SET_MEMLIMIT: {
+        struct hax_set_memlimit *memlimit;
+        memlimit = (struct hax_set_memlimit *)data;
+        ret = hax_set_memlimit(memlimit, sizeof(*memlimit), NULL);
+        break;
+    }
+    case HAX_IOCTL_CREATE_VM: {
+        int vm_id;
+        struct vm_t *cvm;
+
+        cvm = hax_create_vm(&vm_id);
+        if (!cvm) {
+            hax_log_level(HAX_LOGE, "Failed to create the HAX VM\n");
+            ret = ENOMEM;
+            break;
+        }
+
+        *((uint32_t *)data) = vm_id;
+        break;
+    }
+    default:
+        hax_error("Unknown ioctl %#lx, pid=%d ('%s')\n", cmd,
+                  l->l_proc->p_pid, l->l_proc->p_comm);
+        ret = ENOSYS;
+        break;
+    }
+    return ret;
+}
+
+MODULE(MODULE_CLASS_MISC, hax_driver, NULL);
+
+static const struct cfiattrdata haxbus_iattrdata = {
+        "haxbus", 0, { { NULL, NULL, 0 },}
+};
+
+static const struct cfiattrdata *const hax_vm_attrs[] = {
+        &haxbus_iattrdata, NULL
+};
+
+CFDRIVER_DECL(hax_vm, DV_DULL, hax_vm_attrs);
+extern struct cfattach hax_vm_ca;
+static int hax_vmloc[] = {
+        -1,
+        -1,
+        -1
+};
+
+static struct cfdata hax_vm_cfdata[] = {
+        {
+                .cf_name = "hax_vm",
+                .cf_atname = "hax_vm",
+                .cf_unit = 0,
+                .cf_fstate = FSTATE_STAR,
+                .cf_loc = hax_vmloc,
+                .cf_flags = 0,
+                .cf_pspec = NULL,
+        },
+        { NULL, NULL, 0, FSTATE_NOTFOUND, NULL, 0, NULL }
+};
+
+static const struct cfiattrdata *const hax_vcpu_attrs[] = {
+        &haxbus_iattrdata, NULL
+};
+
+CFDRIVER_DECL(hax_vcpu, DV_DULL, hax_vcpu_attrs);
+extern struct cfattach hax_vcpu_ca;
+static int hax_vcpuloc[] = {
+        -1,
+        -1,
+        -1
+};
+
+static struct cfdata hax_vcpu_cfdata[] = {
+        {
+                .cf_name = "hax_vcpu",
+                .cf_atname = "hax_vcpu",
+                .cf_unit = 0,
+                .cf_fstate = FSTATE_STAR,
+                .cf_loc = hax_vcpuloc,
+                .cf_flags = 0,
+                .cf_pspec = NULL,
+        },
+        { NULL, NULL, 0, FSTATE_NOTFOUND, NULL, 0, NULL }
+};
+
+static int
+hax_driver_modcmd(modcmd_t cmd, void *arg __unused)
+{
+    switch (cmd) {
+    case MODULE_CMD_INIT:
+        return hax_driver_init();
+    case MODULE_CMD_FINI:
+        return hax_driver_exit();
+    default:
+        return ENOTTY;
+    }
+}
+
+static int hax_driver_init(void)
+{
+    struct cpu_info *ci;
+    CPU_INFO_ITERATOR cii;
+    struct schedstate_percpu *spc;
+    int i, err;
+    vaddr_t cr4;
+
+    // Initialization
+    max_cpus = 0;
+
+    ci = NULL;
+
+    for (CPU_INFO_FOREACH(cii, ci)) {
+        ++max_cpus;
+        if (!ISSET(ci->ci_schedstate.spc_flags, SPCF_OFFLINE)) {
+            cpu_online_map |= __BIT(ci->ci_cpuid);
+        }
+    }
+
+#if 0
+    cr4 = rcr4();
+    cr4 |= CR4_VMXE;
+    lcr4(cr4);
+#endif
+
+    // Register hax_vm
+    err = config_cfdriver_attach(&hax_vm_cd);
+    if (err) {
+        hax_error("Unable to register cfdriver hax_vm\n");
+        return err;
+    }
+
+    err = config_cfattach_attach(hax_vm_cd.cd_name, &hax_vm_ca);
+    if (err) {
+        hax_error("Unable to register cfattch hax_vm\n");
+        config_cfdriver_detach(&hax_vm_cd);
+        return err;
+    }
+
+    err = config_cfdata_attach(hax_vm_cfdata, 1);
+    if (err) {
+        hax_error("Unable to register cfdata hax_vm\n");
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        return err;
+    }
+
+    // Register hax_vcpu
+    err = config_cfdriver_attach(&hax_vcpu_cd);
+    if (err) {
+        hax_error("Unable to register cfdriver hax_vcpu\n");
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        return err;
+    }
+
+    err = config_cfattach_attach(hax_vcpu_cd.cd_name, &hax_vcpu_ca);
+    if (err) {
+        hax_error("Unable to register cfattch hax_vcpu\n");
+        config_cfdriver_detach(&hax_vcpu_cd);
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        return err;
+    }
+
+    err = config_cfdata_attach(hax_vcpu_cfdata, 1);
+    if (err) {
+        hax_error("Unable to register cfdata hax_vcpu\n");
+        config_cfattach_detach(hax_vcpu_cd.cd_name, &hax_vcpu_ca);
+        config_cfdriver_detach(&hax_vcpu_cd);
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        return err;
+    }
+
+    // Register HAXM
+    err = devsw_attach(HAX_DEVICE_NAME, NULL, &hax_bmajor, &hax_dev_cdevsw,
+                       &hax_cmajor);
+    if (err) {
+        hax_error("Failed to register HAXM device\n");
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+        config_cfdriver_detach(&hax_vm_cd);
+        return ENXIO;
+    }
+
+    config_attach_pseudo(hax_vm_cfdata);
+
+    config_attach_pseudo(hax_vcpu_cfdata);
+
+    // Initialize HAXM
+
+    if (hax_module_init() < 0) {
+        hax_error("Failed to initialize HAXM module\n");
+        return ENXIO;
+    }
+
+    hax_info("Created HAXM device\n");
+    return 0;
+}
+
+static int hax_driver_exit(void)
+{
+    int err;
+
+    if (hax_module_exit() < 0) {
+        hax_error("Failed to finalize HAXM module\n");
+    }
+
+    // hax_vcpu
+    err = config_cfdata_detach(hax_vcpu_cfdata);
+    if (err) {
+        hax_error("Unable to deregister cfattch hax_vcpu\n");
+        return err;
+    }
+    config_cfattach_detach(hax_vcpu_cd.cd_name, &hax_vcpu_ca);
+    config_cfdriver_detach(&hax_vcpu_cd);
+
+    // hax_vm
+    err = config_cfdata_detach(hax_vm_cfdata);
+    if (err) {
+        hax_error("Unable to deregister cfattch hax_vm\n");
+        return err;
+    }
+    config_cfattach_detach(hax_vm_cd.cd_name, &hax_vm_ca);
+    config_cfdriver_detach(&hax_vm_cd);
+
+    // HAX
+
+    devsw_detach(NULL, &hax_dev_cdevsw);
+    hax_info("Removed HAXM device\n");
+
+    return 0;
+}
