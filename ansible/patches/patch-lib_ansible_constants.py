$NetBSD: patch-lib_ansible_constants.py,v 1.0 2016/02/24 22:44:36 tty Exp $

Fix hardcoded paths.

--- lib/ansible/constants.py.orig	2017-06-01 17:00:04.000000000 +0000
+++ lib/ansible/constants.py
@@ -140,7 +140,7 @@ def _get_config(p, section, key, env_var
 
 
 def load_config_file():
-    ''' Load Config File order(first found is used): ENV, CWD, HOME, /etc/ansible '''
+    ''' Load Config File order(first found is used): ENV, CWD, HOME, @PKG_SYSCONFDIR@/ansible '''
 
     p = configparser.ConfigParser()
 
@@ -154,7 +154,7 @@ def load_config_file():
     except OSError:
         path1 = None
     path2 = os.path.expanduser("~/.ansible.cfg")
-    path3 = "/etc/ansible/ansible.cfg"
+    path3 = "@PKG_SYSCONFDIR@/ansible/ansible.cfg"
 
     for path in [path0, path1, path2, path3]:
         if path is not None and os.path.exists(path):
@@ -184,7 +184,7 @@ DEFAULTS='defaults'
 # FIXME: add deprecation warning when these get set
 #### DEPRECATED VARS ####
 # use more sanely named 'inventory'
-DEPRECATED_HOST_LIST  = get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '/etc/ansible/hosts', value_type='path')
+DEPRECATED_HOST_LIST  = get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '@PKG_SYSCONFDIR@/ansible/hosts', value_type='path')
 # this is not used since 0.5 but people might still have in config
 DEFAULT_PATTERN           = get_config(p, DEFAULTS, 'pattern', None, None)
 # If --tags or --skip-tags is given multiple times on the CLI and this is
@@ -197,7 +197,7 @@ MERGE_MULTIPLE_CLI_TAGS = get_config(p, 
 DEFAULT_DEBUG             = get_config(p, DEFAULTS, 'debug',            'ANSIBLE_DEBUG',            False, value_type='boolean')
 DEFAULT_VERBOSITY         = get_config(p, DEFAULTS, 'verbosity',        'ANSIBLE_VERBOSITY',        0, value_type='integer')
 DEFAULT_HOST_LIST         = get_config(p, DEFAULTS,'inventory', 'ANSIBLE_INVENTORY', DEPRECATED_HOST_LIST, value_type='path')
-DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       '/etc/ansible/roles', value_type='pathlist', expand_relative_paths=True)
+DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       '@PKG_SYSCONFDIR@/ansible/roles', value_type='pathlist', expand_relative_paths=True)
 DEFAULT_REMOTE_TMP        = get_config(p, DEFAULTS, 'remote_tmp',       'ANSIBLE_REMOTE_TEMP',      '~/.ansible/tmp')
 DEFAULT_LOCAL_TMP         = get_config(p, DEFAULTS, 'local_tmp',        'ANSIBLE_LOCAL_TEMP',      '~/.ansible/tmp', value_type='tmppath')
 DEFAULT_MODULE_NAME       = get_config(p, DEFAULTS, 'module_name',      None,                       'command')
@@ -287,18 +287,18 @@ DEFAULT_BECOME_ASK_PASS   = get_config(p
 DEFAULT_SQUASH_ACTIONS         = get_config(p, DEFAULTS, 'squash_actions',     'ANSIBLE_SQUASH_ACTIONS', "apk, apt, dnf, homebrew, openbsd_pkg, pacman, pkgng, yum, zypper", value_type='list')
 # paths
 
-DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '~/.ansible/plugins/action:/usr/share/ansible/plugins/action', value_type='pathlist')
-DEFAULT_CACHE_PLUGIN_PATH      = get_config(p, DEFAULTS, 'cache_plugins',      'ANSIBLE_CACHE_PLUGINS', '~/.ansible/plugins/cache:/usr/share/ansible/plugins/cache', value_type='pathlist')
-DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '~/.ansible/plugins/callback:/usr/share/ansible/plugins/callback', value_type='pathlist')
-DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '~/.ansible/plugins/connection:/usr/share/ansible/plugins/connection', value_type='pathlist')
-DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '~/.ansible/plugins/lookup:/usr/share/ansible/plugins/lookup', value_type='pathlist')
+DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '~/.ansible/plugins/action:@PREFIX@/share/ansible/plugins/action', value_type='pathlist')
+DEFAULT_CACHE_PLUGIN_PATH      = get_config(p, DEFAULTS, 'cache_plugins',      'ANSIBLE_CACHE_PLUGINS', '~/.ansible/plugins/cache:@PREFIX@/share/ansible/plugins/cache', value_type='pathlist')
+DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '~/.ansible/plugins/callback:@PREFIX@/share/ansible/plugins/callback', value_type='pathlist')
+DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '~/.ansible/plugins/connection:@PREFIX@/share/ansible/plugins/connection', value_type='pathlist')
+DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '~/.ansible/plugins/lookup:@PREFIX@/share/ansible/plugins/lookup', value_type='pathlist')
 DEFAULT_MODULE_PATH            = get_config(p, DEFAULTS, 'library',            'ANSIBLE_LIBRARY',        None, value_type='pathlist')
 DEFAULT_MODULE_UTILS_PATH      = get_config(p, DEFAULTS, 'module_utils',       'ANSIBLE_MODULE_UTILS',   None, value_type='pathlist')
-DEFAULT_INVENTORY_PLUGIN_PATH  = get_config(p, DEFAULTS, 'inventory_plugins',  'ANSIBLE_INVENTORY_PLUGINS', '~/.ansible/plugins/inventory:/usr/share/ansible/plugins/inventory', value_type='pathlist')
-DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '~/.ansible/plugins/vars:/usr/share/ansible/plugins/vars', value_type='pathlist')
-DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '~/.ansible/plugins/filter:/usr/share/ansible/plugins/filter', value_type='pathlist')
-DEFAULT_TEST_PLUGIN_PATH       = get_config(p, DEFAULTS, 'test_plugins',       'ANSIBLE_TEST_PLUGINS', '~/.ansible/plugins/test:/usr/share/ansible/plugins/test', value_type='pathlist')
-DEFAULT_STRATEGY_PLUGIN_PATH   = get_config(p, DEFAULTS, 'strategy_plugins',   'ANSIBLE_STRATEGY_PLUGINS', '~/.ansible/plugins/strategy:/usr/share/ansible/plugins/strategy', value_type='pathlist')
+DEFAULT_INVENTORY_PLUGIN_PATH  = get_config(p, DEFAULTS, 'inventory_plugins',  'ANSIBLE_INVENTORY_PLUGINS', '~/.ansible/plugins/inventory:@PREFIX@/share/ansible/plugins/inventory', value_type='pathlist')
+DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '~/.ansible/plugins/vars:@PREFIX@/share/ansible/plugins/vars', value_type='pathlist')
+DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '~/.ansible/plugins/filter:@PREFIX@/share/ansible/plugins/filter', value_type='pathlist')
+DEFAULT_TEST_PLUGIN_PATH       = get_config(p, DEFAULTS, 'test_plugins',       'ANSIBLE_TEST_PLUGINS', '~/.ansible/plugins/test:@PREFIX@/share/ansible/plugins/test', value_type='pathlist')
+DEFAULT_STRATEGY_PLUGIN_PATH   = get_config(p, DEFAULTS, 'strategy_plugins',   'ANSIBLE_STRATEGY_PLUGINS', '~/.ansible/plugins/strategy:@PREFIX@/share/ansible/plugins/strategy', value_type='pathlist')
 
 NETWORK_GROUP_MODULES          = get_config(p, DEFAULTS, 'network_group_modules','NETWORK_GROUP_MODULES', ['eos', 'nxos', 'ios', 'iosxr', 'junos',
                                                                                                            'vyos', 'sros', 'dellos9', 'dellos10', 'dellos6'],
