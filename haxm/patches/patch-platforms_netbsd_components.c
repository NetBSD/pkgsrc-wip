$NetBSD$

--- platforms/netbsd/components.c.orig	2018-11-24 22:22:37.786983117 +0000
+++ platforms/netbsd/components.c
@@ -0,0 +1,685 @@
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
+#include <sys/kmem.h>
+#include <sys/lwp.h>
+#include <sys/proc.h>
+#include <sys/module.h>
+
+#include "../../core/include/hax_core_interface.h"
+
+static int hax_vcpu_cmajor = 221, hax_vcpu_bmajor = -1;
+static int hax_vm_cmajor = 222, hax_vm_bmajor = -1;
+
+#define HAX_VM_DEVFS_FMT    "hax_vm/vm%02d"
+#define HAX_VCPU_DEVFS_FMT  "hax_vm%02d/vcpu%02d"
+
+typedef struct hax_vm_netbsd_t {
+    struct vm_t *cvm;
+    int id;
+    struct cdevsw dev;
+    char *devname;
+} hax_vm_netbsd_t;
+
+typedef struct hax_vcpu_netbsd_t {
+    struct vcpu_t *cvcpu;
+    struct hax_vm_netbsd_t *vm;
+    int id;
+    struct cdevsw dev;
+    char *devname;
+} hax_vcpu_netbsd_t;
+
+
+struct hax_vm_softc {
+    device_t sc_dev;
+    struct hax_vm_netbsd_t *vm;
+};
+
+static device_t hax_vm_sc_self;
+
+extern struct cfdriver hax_vm_cd;
+
+static int hax_vm_match(device_t, cfdata_t, void *);
+static void hax_vm_attach(device_t, device_t, void *);
+static int hax_vm_detach(device_t, int);
+
+CFATTACH_DECL_NEW(hax_vm, sizeof(struct hax_vm_softc),
+        hax_vm_match, hax_vm_attach, hax_vm_detach, NULL);
+
+struct hax_vcpu_softc {
+    device_t sc_dev;
+    struct hax_vcpu_netbsd_t *vcpu;
+};
+
+static device_t hax_vcpu_sc_self;
+
+extern struct cfdriver hax_vcpu_cd;
+
+static int hax_vcpu_match(device_t, cfdata_t, void *);
+static void hax_vcpu_attach(device_t, device_t, void *);
+static int hax_vcpu_detach(device_t, int);
+
+CFATTACH_DECL_NEW(hax_vcpu, sizeof(struct hax_vcpu_softc),
+        hax_vcpu_match, hax_vcpu_attach, hax_vcpu_detach, NULL);
+
+dev_type_open(hax_vm_open);
+dev_type_close(hax_vm_close);
+dev_type_ioctl(hax_vm_ioctl);
+
+dev_type_open(hax_vcpu_open);
+dev_type_close(hax_vcpu_close);
+dev_type_ioctl(hax_vcpu_ioctl);
+
+/* Component management */
+
+static hax_vcpu_netbsd_t* hax_vcpu_create_netbsd(struct vcpu_t *cvcpu,
+                                                 hax_vm_netbsd_t *vm,
+                                                 int vcpu_id)
+{
+    hax_vcpu_netbsd_t *vcpu;
+
+    if (!cvcpu || !vm)
+        return NULL;
+
+    vcpu = kmem_zalloc(sizeof(hax_vcpu_netbsd_t), KM_SLEEP);
+    vcpu->cvcpu = cvcpu;
+    vcpu->id = vcpu_id;
+    vcpu->vm = vm;
+    set_vcpu_host(cvcpu, vcpu);
+    return vcpu;
+}
+
+static void hax_vcpu_destroy_netbsd(hax_vcpu_netbsd_t *vcpu)
+{
+    struct vcpu_t *cvcpu;
+
+    if (!vcpu)
+        return;
+
+    cvcpu = vcpu->cvcpu;
+    hax_vcpu_destroy_hax_tunnel(cvcpu);
+    set_vcpu_host(cvcpu, NULL);
+    vcpu->cvcpu = NULL;
+    kmem_free(vcpu, sizeof(hax_vcpu_netbsd_t));
+}
+
+int hax_vcpu_create_host(struct vcpu_t *cvcpu, void *vm_host, int vm_id,
+                         int vcpu_id)
+{
+    int err;
+    hax_vcpu_netbsd_t *vcpu;
+    hax_vm_netbsd_t *vm;
+
+    vm = (hax_vm_netbsd_t *)vm_host;
+    vcpu = hax_vcpu_create_netbsd(cvcpu, vm, vcpu_id);
+    if (!vcpu)
+        return -1;
+
+    vcpu->devname = kmem_asprintf(HAX_VCPU_DEVFS_FMT, vm_id, vcpu_id);
+    vcpu->dev.d_open = hax_vcpu_open;
+    vcpu->dev.d_close = hax_vcpu_close;
+    vcpu->dev.d_read = noread;
+    vcpu->dev.d_write = nowrite;
+    vcpu->dev.d_ioctl = hax_vcpu_ioctl;
+    vcpu->dev.d_stop = nostop;
+    vcpu->dev.d_tty = notty;
+    vcpu->dev.d_poll = nopoll;
+    vcpu->dev.d_mmap = nommap;
+    vcpu->dev.d_kqfilter = nokqfilter;
+    vcpu->dev.d_discard = nodiscard;
+    vcpu->dev.d_flag = D_OTHER;
+
+    err = devsw_attach(vcpu->devname, NULL, &hax_vcpu_bmajor, &vcpu->dev, &hax_vcpu_cmajor);
+    if (err) {
+        hax_error("Failed to register HAXM-VCPU device\n");
+        hax_vcpu_destroy_netbsd(vcpu);
+        return -1;
+    }
+    ((struct hax_vcpu_softc *)device_private(hax_vcpu_sc_self))->vcpu = vcpu;
+    hax_info("Created HAXM-VCPU device '%s'\n", vcpu->devname);
+    return 0;
+}
+
+int hax_vcpu_destroy_host(struct vcpu_t *cvcpu, void *vcpu_host)
+{
+    hax_vcpu_netbsd_t *vcpu;
+
+    vcpu = (hax_vcpu_netbsd_t *)vcpu_host;
+    devsw_detach(NULL, &vcpu->dev);
+    kmem_free(vcpu->devname, strlen(vcpu->devname) + 1);
+
+    hax_vcpu_destroy_netbsd(vcpu);
+    return 0;
+}
+
+static hax_vm_netbsd_t *hax_vm_create_netbsd(struct vm_t *cvm, int vm_id)
+{
+    hax_vm_netbsd_t *vm;
+
+    if (!cvm)
+        return NULL;
+
+    vm = kmem_zalloc(sizeof(hax_vm_netbsd_t), KM_SLEEP);
+    vm->cvm = cvm;
+    vm->id = vm_id;
+    set_vm_host(cvm, vm);
+    return vm;
+}
+
+static void hax_vm_destroy_netbsd(hax_vm_netbsd_t *vm)
+{
+    struct vm_t *cvm;
+
+    if (!vm)
+        return;
+
+    cvm = vm->cvm;
+    set_vm_host(cvm, NULL);
+    vm->cvm = NULL;
+    hax_vm_free_all_ram(cvm);
+    kmem_free(vm, sizeof(hax_vm_netbsd_t));
+}
+
+int hax_vm_create_host(struct vm_t *cvm, int vm_id)
+{
+    int err;
+    hax_vm_netbsd_t *vm;
+
+    vm = hax_vm_create_netbsd(cvm, vm_id);
+    if (!vm)
+        return -1;
+
+    vm->devname = kmem_asprintf(HAX_VM_DEVFS_FMT, vm_id);
+    vm->dev.d_open = hax_vm_open;
+    vm->dev.d_close = hax_vm_close;
+    vm->dev.d_read = noread;
+    vm->dev.d_write = nowrite;
+    vm->dev.d_ioctl = hax_vm_ioctl;
+    vm->dev.d_stop = nostop;
+    vm->dev.d_tty = notty;
+    vm->dev.d_poll = nopoll;
+    vm->dev.d_mmap = nommap;
+    vm->dev.d_kqfilter = nokqfilter;
+    vm->dev.d_discard = nodiscard;
+    vm->dev.d_flag = D_OTHER;
+
+    err = devsw_attach(vm->devname, NULL, &hax_vm_bmajor, &vm->dev, &hax_vm_cmajor);
+    if (err) {
+        hax_error("Failed to register HAXM-VM device\n");
+        hax_vm_destroy_netbsd(vm);
+        return -1;
+    }
+    ((struct hax_vm_softc *)device_private(hax_vm_sc_self))->vm = vm;
+    hax_info("Created HAXM-VM device '%s'\n", vm->devname);
+    return 0;
+}
+
+/* When coming here, all vcpus should have been destroyed already. */
+int hax_vm_destroy_host(struct vm_t *cvm, void *vm_host)
+{
+    hax_vm_netbsd_t *vm;
+
+    vm = (hax_vm_netbsd_t *)vm_host;
+    devsw_detach(NULL, &vm->dev);
+    kmem_free(vm->devname, strlen(vm->devname) + 1);
+
+    hax_vm_destroy_netbsd(vm);
+    return 0;
+}
+
+/* No corresponding function in netbsd side, it can be cleaned later. */
+int hax_destroy_host_interface(void)
+{
+    return 0;
+}
+
+/* VCPU operations */
+
+int hax_vcpu_open(dev_t self, int flag __unused, int mode __unused,
+                         struct lwp *l __unused)
+{
+    struct hax_vcpu_softc *sc;
+    struct vcpu_t *cvcpu;
+    struct hax_vcpu_netbsd_t *vcpu;
+    int ret;
+
+    sc = device_lookup_private(&hax_vcpu_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vcpu failed\n");
+        return ENODEV;
+    }
+    vcpu = sc->vcpu;
+    cvcpu = hax_get_vcpu(vcpu->vm->id, vcpu->id, 1);
+
+    hax_log_level(HAX_LOGD, "HAX vcpu open called\n");
+    if (!cvcpu)
+        return ENODEV;
+
+    ret = hax_vcpu_core_open(cvcpu);
+    if (ret)
+        hax_error("Failed to open core vcpu\n");
+    hax_put_vcpu(cvcpu);
+    return ret;
+}
+
+int hax_vcpu_close(dev_t self, int flag __unused, int mode __unused,
+           struct lwp *l __unused)
+{
+    int ret;
+    struct hax_vcpu_softc *sc;
+    struct vcpu_t *cvcpu;
+    struct hax_vcpu_netbsd_t *vcpu;
+
+    sc = device_lookup_private(&hax_vcpu_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vcpu failed\n");
+        return ENODEV;
+    }
+    vcpu = sc->vcpu;
+    cvcpu = hax_get_vcpu(vcpu->vm->id, vcpu->id, 1);
+
+    hax_log_level(HAX_LOGD, "HAX vcpu close called\n");
+    if (!cvcpu) {
+        hax_error("Failed to find the vcpu, is it closed already?\n");
+        return 0;
+    }
+
+    /* put the one for vcpu create */
+    hax_put_vcpu(cvcpu);
+    /* put the one just held */
+    hax_put_vcpu(cvcpu);
+
+    return 0;
+}
+
+int hax_vcpu_ioctl(dev_t self, u_long cmd, void *data, int flag,
+           struct lwp *l __unused)                         
+{
+    int ret = 0;
+    struct hax_vcpu_softc *sc;
+    struct vcpu_t *cvcpu;
+    struct hax_vcpu_netbsd_t *vcpu;
+
+    sc = device_lookup_private(&hax_vcpu_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vcpu failed\n");
+        return ENODEV;
+    }
+    vcpu = sc->vcpu;
+    cvcpu = hax_get_vcpu(vcpu->vm->id, vcpu->id, 1);
+
+    if (!cvcpu)
+        return ENODEV;
+
+    switch (cmd) {
+    case HAX_VCPU_IOCTL_RUN:
+        ret = vcpu_execute(cvcpu);
+        break;
+    case HAX_VCPU_IOCTL_SETUP_TUNNEL: {
+        struct hax_tunnel_info *info;
+        info = (struct hax_tunnel_info *)data;
+        ret = hax_vcpu_setup_hax_tunnel(cvcpu, info);
+        break;
+    }
+    case HAX_VCPU_IOCTL_SET_MSRS: {
+        struct hax_msr_data *msrs;
+        msrs = (struct hax_msr_data *)data;
+        struct vmx_msr *msr;
+        int i, fail;
+
+        msr = msrs->entries;
+        /* nr_msr needs to be verified */
+        if (msrs->nr_msr >= 0x20) {
+            hax_error("MSRS invalid!\n");
+            ret = EFAULT;
+            break;
+        }
+        for (i = 0; i < msrs->nr_msr; i++, msr++) {
+            fail = vcpu_set_msr(cvcpu, msr->entry, msr->value);
+            if (fail) {
+                break;
+            }
+        }
+        msrs->done = i;
+        break;
+    }
+    case HAX_VCPU_IOCTL_GET_MSRS: {
+        struct hax_msr_data *msrs;
+        msrs = (struct hax_msr_data *)data;
+        struct vmx_msr *msr;
+        int i, fail;
+
+        msr = msrs->entries;
+        if(msrs->nr_msr >= 0x20) {
+            hax_error("MSRS invalid!\n");
+            ret = EFAULT;
+            break;
+        }
+        for (i = 0; i < msrs->nr_msr; i++, msr++) {
+            fail = vcpu_get_msr(cvcpu, msr->entry, &msr->value);
+            if (fail) {
+                break;
+            }
+        }
+        msrs->done = i;
+        break;
+    }
+    case HAX_VCPU_IOCTL_SET_FPU: {
+        struct fx_layout *fl;
+        fl = (struct fx_layout *)data;
+        ret = vcpu_put_fpu(cvcpu, fl);
+        break;
+    }
+    case HAX_VCPU_IOCTL_GET_FPU: {
+        struct fx_layout *fl;
+        fl = (struct fx_layout *)data;
+        ret = vcpu_get_fpu(cvcpu, fl);
+        break;
+    }
+    case HAX_VCPU_SET_REGS: {
+        struct vcpu_state_t *vc_state;
+        vc_state = (struct vcpu_state_t *)data;
+        ret = vcpu_set_regs(cvcpu, vc_state);
+        break;
+    }
+    case HAX_VCPU_GET_REGS: {
+        struct vcpu_state_t *vc_state;
+        vc_state = (struct vcpu_state_t *)data;
+        ret = vcpu_get_regs(cvcpu, vc_state);
+        break;
+    }
+    case HAX_VCPU_IOCTL_INTERRUPT: {
+        uint8_t *vector;
+        vector = (uint8_t *)data;
+        vcpu_interrupt(cvcpu, *vector);
+        break;
+    }
+    case HAX_IOCTL_VCPU_DEBUG: {
+        struct hax_debug_t *hax_debug;
+        hax_debug = (struct hax_debug_t *)data;
+        vcpu_debug(cvcpu, hax_debug);
+        break;
+    }
+    default:
+        // TODO: Print information about the process that sent the ioctl.
+        hax_error("Unknown VCPU IOCTL %#lx, pid=%d ('%s')\n", cmd,
+                  l->l_proc->p_pid, l->l_proc->p_comm);
+        ret = ENOSYS;
+        break;
+    }
+    hax_put_vcpu(cvcpu);
+    return ret;
+}
+
+/* VM operations */
+
+int hax_vm_open(dev_t self, int flag __unused, int mode __unused,
+          struct lwp *l __unused)
+{
+    struct hax_vm_softc *sc;
+    struct vm_t *cvm;
+    struct hax_vm_netbsd_t *vm;
+    int ret;
+
+    sc = device_lookup_private(&hax_vm_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vm failed\n");
+        return ENODEV;
+    }
+
+    vm = sc->vm;
+    cvm = hax_get_vm(vm->id, 1);
+    if (!cvm)
+        return ENODEV;
+
+    ret = hax_vm_core_open(cvm);
+    hax_put_vm(cvm);
+    hax_log_level(HAX_LOGI, "Open VM\n");
+    return ret;
+}
+
+int hax_vm_close(dev_t self __unused, int flag __unused, int mode __unused,
+           struct lwp *l __unused)
+{
+    struct hax_vm_softc *sc;
+    struct vm_t *cvm;
+    struct hax_vm_netbsd_t *vm;
+    int ret;
+
+    sc = device_lookup_private(&hax_vm_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vm failed\n");
+        return ENODEV;
+    }
+
+    vm = sc->vm;
+    cvm = hax_get_vm(vm->id, 1);
+
+    hax_log_level(HAX_LOGI, "Close VM\n");
+    if (cvm) {
+        /* put the ref get just now */
+        hax_put_vm(cvm);
+        hax_put_vm(cvm);
+    }
+    return 0;
+}
+
+int hax_vm_ioctl(dev_t self __unused, u_long cmd, void *data, int flag,
+           struct lwp *l __unused)
+{
+    int ret = 0;
+    struct vm_t *cvm;
+    struct hax_vm_netbsd_t *vm;
+    struct hax_vm_softc *sc;
+
+    sc = device_lookup_private(&hax_vm_cd, minor(self));
+    if (sc == NULL) {
+        hax_error("device_lookup_private() for hax_vm failed\n");
+        return ENODEV;
+    }
+    vm = sc->vm;
+    cvm = hax_get_vm(vm->id, 1);
+    if (!cvm)
+        return ENODEV;
+
+    switch (cmd) {
+    case HAX_VM_IOCTL_VCPU_CREATE:
+    case HAX_VM_IOCTL_VCPU_CREATE_ORIG: {
+        uint32_t *vcpu_id, vm_id;
+        vcpu_id = (uint32_t *)data;
+        struct vcpu_t *cvcpu;
+
+        vm_id = vm->id;
+        cvcpu = vcpu_create(cvm, vm, *vcpu_id);
+        if (!cvcpu) {
+            hax_error("Failed to create vcpu %x on vm %x\n", *vcpu_id, vm_id);
+            ret = -EINVAL;
+            break;
+        }
+        break;
+    }
+    case HAX_VM_IOCTL_ALLOC_RAM: {
+        struct hax_alloc_ram_info *info;
+        info = (struct hax_alloc_ram_info *)data;
+        hax_info("IOCTL_ALLOC_RAM: vm_id=%d, va=0x%llx, size=0x%x, pad=0x%x\n",
+                 vm->id, info->va, info->size, info->pad);
+        ret = hax_vm_add_ramblock(cvm, info->va, info->size);
+        break;
+    }
+    case HAX_VM_IOCTL_ADD_RAMBLOCK: {
+        struct hax_ramblock_info *info;
+        info = (struct hax_ramblock_info *)data;
+        if (info->reserved) {
+            hax_error("IOCTL_ADD_RAMBLOCK: vm_id=%d, reserved=0x%llx\n",
+                      vm->id, info->reserved);
+            ret = EINVAL;
+            break;
+        }
+        hax_info("IOCTL_ADD_RAMBLOCK: vm_id=%d, start_va=0x%llx, size=0x%llx\n",
+                 vm->id, info->start_va, info->size);
+        ret = hax_vm_add_ramblock(cvm, info->start_va, info->size);
+        break;
+    }
+    case HAX_VM_IOCTL_SET_RAM: {
+        struct hax_set_ram_info *info;
+        info = (struct hax_set_ram_info *)data;
+        ret = hax_vm_set_ram(cvm, info);
+        break;
+    }
+#ifdef CONFIG_HAX_EPT2
+    case HAX_VM_IOCTL_SET_RAM2: {
+        struct hax_set_ram_info2 *info;
+        info = (struct hax_set_ram_info2 *)data;
+        if (info->reserved1 || info->reserved2) {
+            hax_error("IOCTL_SET_RAM2: vm_id=%d, reserved1=0x%x reserved2=0x%llx\n",
+                      vm->id, info->reserved1, info->reserved2);
+            ret = EINVAL;
+            break;
+        }
+        ret = hax_vm_set_ram2(cvm, info);
+        break;
+    }
+    case HAX_VM_IOCTL_PROTECT_RAM: {
+        struct hax_protect_ram_info *info;
+        info = (struct hax_protect_ram_info *)data;
+        if (info->reserved) {
+            hax_error("IOCTL_PROTECT_RAM: vm_id=%d, reserved=0x%x\n",
+                      vm->id, info->reserved);
+            ret = EINVAL;
+            break;
+        }
+        ret = hax_vm_protect_ram(cvm, info);
+        break;
+    }
+#endif
+    case HAX_VM_IOCTL_NOTIFY_QEMU_VERSION: {
+        struct hax_qemu_version *info;
+        info = (struct hax_qemu_version *)data;
+        // TODO: Print information about the process that sent the ioctl.
+        ret = hax_vm_set_qemuversion(cvm, info);
+        break;
+    }
+    default:
+        // TODO: Print information about the process that sent the ioctl.
+        hax_error("Unknown VM IOCTL %#lx, pid=%d ('%s')\n", cmd,
+                  l->l_proc->p_pid, l->l_proc->p_comm);
+        break;
+    }
+    hax_put_vm(cvm);
+    return ret;
+}
+
+static int
+hax_vm_match(device_t parent, cfdata_t match, void *aux)
+{
+    return 1;
+}
+
+static void
+hax_vm_attach(device_t parent, device_t self, void *aux)
+{
+    struct hax_vm_softc *sc;
+
+    if (hax_vm_sc_self)
+        return;
+
+    sc = device_private(self);
+    if (sc == NULL) {
+        hax_error("device_private() for hax_vm failed\n");
+        return;
+    }
+    sc->sc_dev = self;
+    hax_vm_sc_self = self;
+
+    if (!pmf_device_register(self, NULL, NULL))
+        aprint_error_dev(self, "couldn't establish power handler\n");
+}
+
+static int
+hax_vm_detach(device_t self, int flags)
+{
+    struct hax_vm_softc *sc;
+
+    sc = device_private(self);
+    if (sc == NULL) {
+        hax_error("device_private() for hax_vm failed\n");
+        return ENODEV;
+    }
+    pmf_device_deregister(self);
+
+    hax_vm_sc_self = NULL;
+    return 0;
+}
+
+static int
+hax_vcpu_match(device_t parent, cfdata_t match, void *aux)
+{
+    return 1;
+}
+
+static void
+hax_vcpu_attach(device_t parent, device_t self, void *aux)
+{
+    struct hax_vcpu_softc *sc;
+
+    if (hax_vcpu_sc_self)
+        return;
+
+    sc = device_private(self);
+    if (sc == NULL) {
+        hax_error("device_private() for hax_vcpu failed\n");
+        return;
+    }
+    sc->sc_dev = self;
+    hax_vcpu_sc_self = self;
+
+    if (!pmf_device_register(self, NULL, NULL))
+        aprint_error_dev(self, "couldn't establish power handler\n");
+}
+
+static int
+hax_vcpu_detach(device_t self, int flags)
+{
+    struct hax_vcpu_softc *sc;
+
+    sc = device_private(self);
+    if (sc == NULL) {
+        hax_error("device_private() for hax_vm failed\n");
+        return ENODEV;
+    }
+    pmf_device_deregister(self);
+
+    hax_vcpu_sc_self = NULL;
+    return 0;
+}
