$NetBSD: patch-src_mesa_drivers_dri_i965_brw__performance__query.c,v 1.2 2018/10/16 15:21:20 jperkin Exp $

--- src/mesa/drivers/dri/i965/brw_performance_query.c.orig	2019-02-21 18:11:53.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_performance_query.c
@@ -1797,6 +1797,9 @@ enumerate_sysfs_metrics(struct brw_conte
    DIR *metricsdir = NULL;
    struct dirent *metric_entry;
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    len = snprintf(buf, sizeof(buf), "%s/metrics", brw->perfquery.sysfs_dev_dir);
    if (len < 0 || len >= sizeof(buf)) {
@@ -1813,10 +1816,19 @@ enumerate_sysfs_metrics(struct brw_conte
    while ((metric_entry = readdir(metricsdir))) {
       struct hash_entry *entry;
 
+#if defined(__sun)
+      stat(metric_entry->d_name, &s);
+      if ((s.st_mode != S_IFDIR &&
+           s.st_mode != S_IFLNK) ||
+          metric_entry->d_name[0] == '.')
+         continue;
+#else
+
       if ((metric_entry->d_type != DT_DIR &&
            metric_entry->d_type != DT_LNK) ||
           metric_entry->d_name[0] == '.')
          continue;
+#endif
 
       DBG("metric set: %s\n", metric_entry->d_name);
       entry = _mesa_hash_table_search(brw->perfquery.oa_metrics_table,
@@ -2056,6 +2068,9 @@ get_sysfs_dev_dir(struct brw_context *br
    DIR *drmdir;
    struct dirent *drm_entry;
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    brw->perfquery.sysfs_dev_dir[0] = '\0';
 
@@ -2087,9 +2102,16 @@ get_sysfs_dev_dir(struct brw_context *br
    }
 
    while ((drm_entry = readdir(drmdir))) {
+#if defined(__sun)
+      stat(drm_entry->d_name, &s);
+      if ((s.st_mode == S_IFDIR ||
+           s.st_mode == S_IFLNK) &&
+          strncmp(drm_entry->d_name, "card", 4) == 0)
+#else
       if ((drm_entry->d_type == DT_DIR ||
            drm_entry->d_type == DT_LNK) &&
           strncmp(drm_entry->d_name, "card", 4) == 0)
+#endif
       {
          len = snprintf(brw->perfquery.sysfs_dev_dir,
                         sizeof(brw->perfquery.sysfs_dev_dir),
