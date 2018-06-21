$NetBSD$

Add NetBSD backend and deal with group removal.

--- files/usr/share/cinnamon/cinnamon-settings-users/cinnamon-settings-users.py.orig	2018-05-26 23:40:41.000000000 +0000
+++ files/usr/share/cinnamon/cinnamon-settings-users/cinnamon-settings-users.py
@@ -573,6 +573,29 @@ class Module:
             dialog = PasswordDialog(user, self.password_mask, self.groups_label, self.window)
             response = dialog.run()
 
+    def _remove_from_group(self, username, group):
+        with open('/etc/group', 'r') as group_file:
+            groups = group_file.read()
+        grouplines = groups.splitlines()
+        for entry in grouplines:
+            fields = entry.split(':')
+            if group == fields[0]:
+                users = fields[3].split(',')
+                users[-1] = users[-1].rstrip()
+                if username in users:
+                    newentry = entry
+                    replace = [
+                        (r'\b' + username + r'\b', ''),
+                        (',,', ','),
+                        (':,', ':'),
+                        (r',$', '')
+                    ]
+                    for old, new in replace:
+                        newentry = re.sub(old, new, newentry)
+                    newgroups = groups.replace(entry, newentry)
+                    with open("/etc/group", "w") as group_file:
+                        group_file.write(newgroups)
+
     def _on_groups_button_clicked(self, widget):
         model, treeiter = self.users_treeview.get_selection().get_selected()
         if treeiter != None:
@@ -581,7 +604,15 @@ class Module:
             response = dialog.run()
             if response == Gtk.ResponseType.OK:
                 groups = dialog.get_selected_groups()
-                subprocess.call(["usermod", user.get_user_name(), "-G", ",".join(groups)])
+                # Add groups for user
+                subprocess.call(["usermod", "-G", ",".join(groups), user.get_user_name()])
+                # Remove deselected groups for user
+                old_groups = set(map(str.strip, self.groups_label.get_text().split(",")))
+                new_groups = set(map(str.strip, groups))
+                if new_groups < old_groups:
+                    for del_group in old_groups - new_groups:
+                        self._remove_from_group(user.get_user_name(), del_group)
+
                 groups.sort()
                 self.groups_label.set_text(", ".join(groups))
             dialog.destroy()
@@ -593,6 +624,8 @@ class Module:
             if self.account_type_combo.get_active() == 1:
                 user.set_account_type(AccountsService.UserAccountType.ADMINISTRATOR)
             else:
+                # Remove user from wheel
+                self._remove_from_group(user.get_user_name(), "wheel")
                 user.set_account_type(AccountsService.UserAccountType.STANDARD)
 
             groups = []
@@ -748,7 +781,16 @@ class Module:
             else:
                 self.password_mask.set_text(_("Set at login"))
 
-            if user.get_account_type() == AccountsService.UserAccountType.ADMINISTRATOR:
+            groups = []
+            is_admin = False
+            for group in grp.getgrall():
+                if user.get_user_name() in group[3]:
+                    groups.append(group[0])
+                    if group[0] == "wheel":
+                        is_admin = True
+            groups.sort()
+
+            if is_admin:
                 self.account_type_combo.set_active(1)
             else:
                 self.account_type_combo.set_active(0)
@@ -779,17 +821,12 @@ class Module:
                     print(message)
                 self.face_image.set_from_file("/usr/share/cinnamon/faces/user-generic.png")
 
-            groups = []
-            for group in grp.getgrall():
-                if user.get_user_name() in group[3]:
-                    groups.append(group[0])
-            groups.sort()
             self.groups_label.set_text(", ".join(groups))
             self.builder.get_object("box_users").show()
 
             # Count the number of connections for the currently logged-in user
-            connections = int(subprocess.check_output(["w", "-hs", user.get_user_name()]).decode("utf-8").count("\n"))
-            if connections > 0:
+            connections = int(subprocess.check_output(["w", "-h", user.get_user_name()]).decode("utf-8").count("\n"))
+            if connections > 1:
                 self.builder.get_object("button_delete_user").set_sensitive(False)
                 self.builder.get_object("button_delete_user").set_tooltip_text(_("This user is currently logged in"))
             else:
@@ -840,10 +877,11 @@ class Module:
             description = "<b>%s</b>\n%s" % (fullname, username)
             piter = self.users.append(None, [new_user, pixbuf, description])
             # Add the user to his/her own group and sudo if Administrator was selected
-            if dialog.account_type_combo.get_active() == 1:
-                subprocess.call(["usermod", username, "-G", "%s,sudo,nopasswdlogin" % username])
-            else:
-                subprocess.call(["usermod", username, "-G", "%s,nopasswdlogin" % username])
+            #if dialog.account_type_combo.get_active() == 1:
+            #    print("trying to add to admins...")
+            #    subprocess.call(["usermod", "-G", "%s,sudo,nopasswdlogin" % username, username])
+            #else:
+            #    subprocess.call(["usermod", "-G", "%s,nopasswdlogin" % username, username])
             self.load_groups()
         dialog.destroy()
 
@@ -907,7 +945,7 @@ class Module:
             dialog = GroupDialog(_("Group Name"), group, self.window)
             response = dialog.run()
             if response == Gtk.ResponseType.OK:
-                subprocess.call(["groupmod", group, "-n", dialog.entry.get_text().lower()])
+                subprocess.call(["groupmod", "-n", dialog.entry.get_text().lower(), group])
                 self.load_groups()
             dialog.destroy()
 
