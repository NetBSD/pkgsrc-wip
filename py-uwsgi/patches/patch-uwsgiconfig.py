--- uwsgiconfig.py.orig	2013-12-30 08:44:59.000000000 +0000
+++ uwsgiconfig.py
@@ -816,6 +816,8 @@ class uConf(object):
         if locking_mode == 'auto':
             if uwsgi_os == 'Linux' or uwsgi_os == 'SunOS':
                 locking_mode = 'pthread_mutex'
+            elif uwsgi_os == 'NetBSD':
+                locking_mode = 'posix_sem';
             # FreeBSD umtx is still not ready for process shared locking
             # starting from FreeBSD 9 posix semaphores can be shared between processes
             elif uwsgi_os in ('FreeBSD', 'GNU/kFreeBSD'):
@@ -975,7 +977,7 @@ class uConf(object):
         has_pcre = False
 
         # re-enable after pcre fix
-        if self.get('pcre'):
+        if self.get('pcreOFF'):
             if self.get('pcre') == 'auto':
                 pcreconf = spcall('pcre-config --libs')
                 if pcreconf:
@@ -1019,7 +1021,7 @@ class uConf(object):
             self.libs.append('-lcap')
             report['capabilities'] = True
 
-        if self.has_include('uuid/uuid.h'):
+        if False and self.has_include('uuid/uuid.h'):
             self.cflags.append("-DUWSGI_UUID")
             if uwsgi_os in ('Linux', 'GNU', 'GNU/kFreeBSD') or uwsgi_os.startswith('CYGWIN') or os.path.exists('/usr/lib/libuuid.so') or os.path.exists('/usr/local/lib/libuuid.so') or os.path.exists('/usr/lib64/libuuid.so') or os.path.exists('/usr/local/lib64/libuuid.so'):
                 self.libs.append('-luuid')
@@ -1107,7 +1109,7 @@ class uConf(object):
         self.cflags.append('-DUWSGI_VERSION_REVISION="' + uver_rev + '"')
         self.cflags.append('-DUWSGI_VERSION_CUSTOM="\\"' + uver_custom + '\\""')
 
-        if self.get('yaml'):
+        if self.get('yamlOFF'):
             self.cflags.append("-DUWSGI_YAML")
             self.gcc_list.append('core/yaml')
             report['yaml'] = 'embedded'
@@ -1116,7 +1118,7 @@ class uConf(object):
                 self.libs.append('-lyaml')
                 report['yaml'] = 'libyaml'
 
-        if self.get('json'):
+        if self.get('jsonOFF'):
             if self.get('json') == 'auto':
                 jsonconf = spcall("pkg-config --cflags jansson")
                 if jsonconf:
