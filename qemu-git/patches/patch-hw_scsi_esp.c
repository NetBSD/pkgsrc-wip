$NetBSD$

--- hw/scsi/esp.c.orig	2017-08-25 15:26:30.000000000 +0000
+++ hw/scsi/esp.c
@@ -593,7 +593,7 @@ const VMStateDescription vmstate_esp = {
 };
 
 #define TYPE_ESP "esp"
-#define ESP(obj) OBJECT_CHECK(SysBusESPState, (obj), TYPE_ESP)
+#define QESP(obj) OBJECT_CHECK(SysBusESPState, (obj), TYPE_ESP)
 
 typedef struct {
     /*< private >*/
@@ -644,7 +644,7 @@ void esp_init(hwaddr espaddr, int it_shi
     ESPState *esp;
 
     dev = qdev_create(NULL, TYPE_ESP);
-    sysbus = ESP(dev);
+    sysbus = QESP(dev);
     esp = &sysbus->esp;
     esp->dma_memory_read = dma_memory_read;
     esp->dma_memory_write = dma_memory_write;
@@ -672,7 +672,7 @@ static const struct SCSIBusInfo esp_scsi
 
 static void sysbus_esp_gpio_demux(void *opaque, int irq, int level)
 {
-    SysBusESPState *sysbus = ESP(opaque);
+    SysBusESPState *sysbus = QESP(opaque);
     ESPState *s = &sysbus->esp;
 
     switch (irq) {
@@ -688,7 +688,7 @@ static void sysbus_esp_gpio_demux(void *
 static void sysbus_esp_realize(DeviceState *dev, Error **errp)
 {
     SysBusDevice *sbd = SYS_BUS_DEVICE(dev);
-    SysBusESPState *sysbus = ESP(dev);
+    SysBusESPState *sysbus = QESP(dev);
     ESPState *s = &sysbus->esp;
 
     sysbus_init_irq(sbd, &s->irq);
@@ -706,7 +706,7 @@ static void sysbus_esp_realize(DeviceSta
 
 static void sysbus_esp_hard_reset(DeviceState *dev)
 {
-    SysBusESPState *sysbus = ESP(dev);
+    SysBusESPState *sysbus = QESP(dev);
     esp_hard_reset(&sysbus->esp);
 }
 
