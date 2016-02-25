$NetBSD: patch-lib_ansible_constants.py,v 1.0 2016/02/24 22:44:36 tty Exp $

Fix hardcoded paths.

--- lib/ansible/constants.py.orig	2016-02-24 13:04:04.000000000 +0000
+++ lib/ansible/constants.py
@@ -83,7 +83,7 @@ def _get_config(p, section, key, env_var
     return default
 
 def load_config_file():
-    ''' Load Config File order(first found is used): ENV, CWD, HOME, /etc/ansible '''
+    ''' Load Config File order(first found is used): ENV, CWD, HOME, @PKG_SYSCONFDIR@/ansible '''
 
     p = configparser.ConfigParser()
 
@@ -94,7 +94,7 @@ def load_config_file():
             path0 += "/ansible.cfg"
     path1 = os.getcwd() + "/ansible.cfg"
     path2 = os.path.expanduser("~/.ansible.cfg")
-    path3 = "/etc/ansible/ansible.cfg"
+    path3 = "@PKG_SYSCONFDIR@/ansible/ansible.cfg"
 
     for path in [path0, path1, path2, path3]:
         if path is not None and os.path.exists(path):
@@ -123,7 +123,7 @@ DEFAULTS='defaults'
 # FIXME: add deprecation warning when these get set
 #### DEPRECATED VARS #### 
 # use more sanely named 'inventory'
-DEPRECATED_HOST_LIST  = get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '/etc/ansible/hosts', ispath=True)
+DEPRECATED_HOST_LIST  = get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '@PKG_SYSCONFDIR@/ansible/hosts', ispath=True)
 # this is not used since 0.5 but people might still have in config
 DEFAULT_PATTERN           = get_config(p, DEFAULTS, 'pattern', None, None)
 
@@ -131,7 +131,7 @@ DEFAULT_PATTERN           = get_config(p
 DEFAULT_DEBUG             = get_config(p, DEFAULTS, 'debug',            'ANSIBLE_DEBUG',            False, boolean=True)
 DEFAULT_HOST_LIST         = get_config(p, DEFAULTS,'inventory', 'ANSIBLE_INVENTORY', DEPRECATED_HOST_LIST, ispath=True)
 DEFAULT_MODULE_PATH       = get_config(p, DEFAULTS, 'library',          'ANSIBLE_LIBRARY',          None, ispath=True)
-DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       '/etc/ansible/roles', ispath=True)
+DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       '@PKG_SYSCONFDIR@/ansible/roles', ispath=True)
 DEFAULT_REMOTE_TMP        = get_config(p, DEFAULTS, 'remote_tmp',       'ANSIBLE_REMOTE_TEMP',      '$HOME/.ansible/tmp')
 DEFAULT_MODULE_NAME       = get_config(p, DEFAULTS, 'module_name',      None,                       'command')
 DEFAULT_FORKS             = get_config(p, DEFAULTS, 'forks',            'ANSIBLE_FORKS',            5, integer=True)
@@ -203,15 +203,15 @@ DEFAULT_BECOME_ASK_PASS   = get_config(p
 # (mapping of param: squash field)
 DEFAULT_SQUASH_ACTIONS         = get_config(p, DEFAULTS, 'squash_actions',     'ANSIBLE_SQUASH_ACTIONS', "apt, dnf, package, pkgng, yum, zypper", islist=True)
 # paths
-DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '~/.ansible/plugins/action:/usr/share/ansible/plugins/action', ispath=True)
-DEFAULT_CACHE_PLUGIN_PATH      = get_config(p, DEFAULTS, 'cache_plugins',      'ANSIBLE_CACHE_PLUGINS', '~/.ansible/plugins/cache:/usr/share/ansible/plugins/cache', ispath=True)
-DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '~/.ansible/plugins/callback:/usr/share/ansible/plugins/callback', ispath=True)
-DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '~/.ansible/plugins/connection:/usr/share/ansible/plugins/connection', ispath=True)
-DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '~/.ansible/plugins/lookup:/usr/share/ansible/plugins/lookup', ispath=True)
-DEFAULT_INVENTORY_PLUGIN_PATH  = get_config(p, DEFAULTS, 'inventory_plugins',  'ANSIBLE_INVENTORY_PLUGINS', '~/.ansible/plugins/inventory:/usr/share/ansible/plugins/inventory', ispath=True)
-DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '~/.ansible/plugins/vars:/usr/share/ansible/plugins/vars', ispath=True)
-DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '~/.ansible/plugins/filter:/usr/share/ansible/plugins/filter', ispath=True)
-DEFAULT_TEST_PLUGIN_PATH       = get_config(p, DEFAULTS, 'test_plugins',       'ANSIBLE_TEST_PLUGINS', '~/.ansible/plugins/test:/usr/share/ansible/plugins/test', ispath=True)
+DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '~/.ansible/plugins/action:@PREFIX@/share/ansible/plugins/action', ispath=True)
+DEFAULT_CACHE_PLUGIN_PATH      = get_config(p, DEFAULTS, 'cache_plugins',      'ANSIBLE_CACHE_PLUGINS', '~/.ansible/plugins/cache:@PREFIX@/share/ansible/plugins/cache', ispath=True)
+DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '~/.ansible/plugins/callback:@PREFIX@/share/ansible/plugins/callback', ispath=True)
+DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '~/.ansible/plugins/connection:@PREFIX@/share/ansible/plugins/connection', ispath=True)
+DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '~/.ansible/plugins/lookup:@PREFIX@/share/ansible/plugins/lookup', ispath=True)
+DEFAULT_INVENTORY_PLUGIN_PATH  = get_config(p, DEFAULTS, 'inventory_plugins',  'ANSIBLE_INVENTORY_PLUGINS', '~/.ansible/plugins/inventory:@PREFIX@/share/ansible/plugins/inventory', ispath=True)
+DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '~/.ansible/plugins/vars:@PREFIX@/share/ansible/plugins/vars', ispath=True)
+DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '~/.ansible/plugins/filter:@PREFIX@/share/ansible/plugins/filter', ispath=True)
+DEFAULT_TEST_PLUGIN_PATH       = get_config(p, DEFAULTS, 'test_plugins',       'ANSIBLE_TEST_PLUGINS', '~/.ansible/plugins/test:@PREFIX@/share/ansible/plugins/test', ispath=True)
 DEFAULT_STDOUT_CALLBACK        = get_config(p, DEFAULTS, 'stdout_callback',    'ANSIBLE_STDOUT_CALLBACK', 'default')
 # cache
 CACHE_PLUGIN                   = get_config(p, DEFAULTS, 'fact_caching', 'ANSIBLE_CACHE_PLUGIN', 'memory')
