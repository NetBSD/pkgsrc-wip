$NetBSD$

--- libs/gum/prof/gumbusycyclesampler-netbsd.c.orig	2018-03-15 03:53:19.250967215 +0000
+++ libs/gum/prof/gumbusycyclesampler-netbsd.c
@@ -0,0 +1,60 @@
+/*
+ * Copyright (C) 2015 Ole André Vadla Ravnås <ole.andre.ravnas@tillitech.com>
+ *
+ * Licence: wxWindows Library Licence, Version 3.1
+ */
+
+#include "gumbusycyclesampler.h"
+
+static void gum_busy_cycle_sampler_iface_init (gpointer g_iface,
+    gpointer iface_data);
+static GumSample gum_busy_cycle_sampler_sample (GumSampler * sampler);
+
+G_DEFINE_TYPE_EXTENDED (GumBusyCycleSampler,
+                        gum_busy_cycle_sampler,
+                        G_TYPE_OBJECT,
+                        0,
+                        G_IMPLEMENT_INTERFACE (GUM_TYPE_SAMPLER,
+                                               gum_busy_cycle_sampler_iface_init));
+
+static void
+gum_busy_cycle_sampler_class_init (GumBusyCycleSamplerClass * klass)
+{
+}
+
+static void
+gum_busy_cycle_sampler_iface_init (gpointer g_iface,
+                                   gpointer iface_data)
+{
+  GumSamplerIface * iface = (GumSamplerIface *) g_iface;
+
+  iface->sample = gum_busy_cycle_sampler_sample;
+}
+
+static void
+gum_busy_cycle_sampler_init (GumBusyCycleSampler * self)
+{
+}
+
+GumSampler *
+gum_busy_cycle_sampler_new (void)
+{
+  GumBusyCycleSampler * sampler;
+
+  sampler = g_object_new (GUM_TYPE_BUSY_CYCLE_SAMPLER, NULL);
+
+  return GUM_SAMPLER (sampler);
+}
+
+gboolean
+gum_busy_cycle_sampler_is_available (GumBusyCycleSampler * self)
+{
+  return FALSE;
+}
+
+static GumSample
+gum_busy_cycle_sampler_sample (GumSampler * sampler)
+{
+  /* TODO: implement */
+  return 0;
+}
