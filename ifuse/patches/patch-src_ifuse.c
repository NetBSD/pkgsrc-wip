$NetBSD$

Workaround for the lack of -omodules=subdir support in NetBSD
refuse(3). Without this patch `ifuse --documents {APP-ID}` cannot
work. ifuse can successfully mount the volume but it becomes empty.

Definitely not for upstreaming. We should really implement it in
refuse(3). It has the fuse_fs API but I (pho@) somehow forgot to implement
the -omodules option which is needed for actually using the API from user
code. Derp.

--- src/ifuse.c.orig	2025-10-10 17:02:39.000000000 +0000
+++ src/ifuse.c
@@ -597,6 +597,304 @@ static struct fuse_operations ifuse_oper
 	.destroy = ifuse_cleanup
 };
 
+#include <assert.h>
+char const* subdir = NULL;
+
+static int prefix_subdir(const char *path, char **new_path_p)
+{
+	assert(new_path_p != NULL);
+	assert(subdir != NULL);
+
+	char* new_path = NULL;
+	if (path) {
+		new_path = malloc(strlen(subdir) + strlen(path) + 2);
+		if (!new_path) {
+			return -ENOMEM;
+		}
+
+		/* I don't know if omitting the preceding '/' is the right
+		 * thing or not, but this is what FUSE's subdir module does.
+		 */
+		char* pos = stpcpy(new_path, subdir);
+		*(pos++) = '/';
+		if (path[0] == '/') {
+			path++;
+		}
+		(void)strcpy(pos, path);
+		if (!new_path[0]) {
+			(void)strcpy(new_path, ".");
+		}
+	}
+	*new_path_p = new_path;
+
+	return 0;
+}
+
+static int ifuse_subdir_getattr(const char *path, struct stat *stbuf, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_getattr(new_path, stbuf, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_statfs(const char *path, struct statvfs *stbuf)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_statfs(new_path, stbuf);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_readdir(const char *path, void *buf,
+				fuse_fill_dir_t filler, off_t offset,
+				struct fuse_file_info *fi, enum fuse_readdir_flags flags)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_readdir(new_path, buf, filler, offset, fi, flags);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_mkdir(const char *path, mode_t mode)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_mkdir(new_path, mode);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_unlink(const char *path)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_unlink(new_path);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_create(const char *path, mode_t mode, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_create(new_path, mode, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_open(const char *path, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_open(new_path, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_read(const char *path, char *buf, size_t size,
+			     off_t offset, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_read(new_path, buf, size, offset, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_write(const char *path, const char *buf, size_t size,
+			      off_t offset, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_write(new_path, buf, size, offset, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_truncate(const char *path, off_t size, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_truncate(new_path, size, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_readlink(const char *path, char *buf, size_t size)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_readlink(new_path, buf, size);
+		/* We don't transform absolute symlinks because (1) the
+		 * original ifuse doesn't specify the -orellinks option,
+		 * and (2) the original ifuse specifies -osubdir=Documents,
+		 * which doesn't begin with '/'. Absolute symlinks are
+		 * unsound in this context anyway.
+		 */
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_symlink(const char *from, const char *path)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_symlink(from, new_path);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_link(const char *from, const char *to)
+{
+	char* new_from;
+	char* new_to;
+	int err = prefix_subdir(from, &new_from);
+	if (!err) {
+		err = prefix_subdir(to, &new_to);
+		if (!err) {
+			err = ifuse_link(new_from, new_to);
+			free(new_to);
+		}
+		free(new_from);
+	}
+	return err;
+}
+
+static int ifuse_subdir_rename(const char *from, const char *to, unsigned int flags)
+{
+	char* new_from;
+	char* new_to;
+	int err = prefix_subdir(from, &new_from);
+	if (!err) {
+		err = prefix_subdir(to, &new_to);
+		if (!err) {
+			err = ifuse_rename(new_from, new_to, flags);
+			free(new_to);
+		}
+		free(new_from);
+	}
+	return err;
+}
+
+static int ifuse_subdir_utimens(const char *path, const struct timespec ts[2],
+				struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_utimens(new_path, ts, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_fsync(const char *path, int isdatasync, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_fsync(new_path, isdatasync, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_chmod(const char *path, mode_t mode, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_chmod(new_path, mode, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_chown(const char *path, uid_t uid, gid_t gid, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_chown(new_path, uid, gid, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static int ifuse_subdir_release(const char *path, struct fuse_file_info *fi)
+{
+	char* new_path;
+	int err = prefix_subdir(path, &new_path);
+	if (!err) {
+		err = ifuse_release(new_path, fi);
+		free(new_path);
+	}
+	return err;
+}
+
+static void *ifuse_subdir_init(struct fuse_conn_info *conn, struct fuse_config *cfg)
+{
+	return ifuse_init(conn, cfg);
+}
+
+static void ifuse_subdir_destroy(void *data)
+{
+	ifuse_cleanup(data);
+}
+
+static struct fuse_operations ifuse_subdir_oper = {
+	.getattr = ifuse_subdir_getattr,
+	.statfs = ifuse_subdir_statfs,
+	.readdir = ifuse_subdir_readdir,
+	.mkdir = ifuse_subdir_mkdir,
+	.rmdir = ifuse_subdir_unlink,
+	.create = ifuse_subdir_create,
+	.open = ifuse_subdir_open,
+	.read = ifuse_subdir_read,
+	.write = ifuse_subdir_write,
+	.truncate = ifuse_subdir_truncate,
+	.readlink = ifuse_subdir_readlink,
+	.symlink = ifuse_subdir_symlink,
+	.link = ifuse_subdir_link,
+	.unlink = ifuse_subdir_unlink,
+	.rename = ifuse_subdir_rename,
+	.utimens = ifuse_subdir_utimens,
+	.fsync = ifuse_subdir_fsync,
+	.chmod = ifuse_subdir_chmod,
+	.chown = ifuse_subdir_chown,
+	.release = ifuse_subdir_release,
+	.init = ifuse_subdir_init,
+	.destroy = ifuse_subdir_destroy
+};
+
 static void print_usage()
 {
 	fprintf(stderr, "Usage: " PACKAGE_NAME " MOUNTPOINT [OPTIONS]\n");
@@ -848,6 +1146,7 @@ int main(int argc, char *argv[])
 		return EXIT_FAILURE;
 	}
 
+	struct fuse_operations const* oper = &ifuse_oper;
 	if (!strcmp(opts.service_name, HOUSE_ARREST_SERVICE_NAME)) {
 		house_arrest_client_new(device, opts.service, &house_arrest);
 		if (!house_arrest) {
@@ -880,11 +1179,11 @@ int main(int argc, char *argv[])
 		plist_free(dict);
 
 		if (opts.use_container == 0) {
-			fuse_opt_add_arg(&args, "-omodules=subdir");
-			fuse_opt_add_arg(&args, "-osubdir=Documents");
+			oper = &ifuse_subdir_oper;
+			subdir = "Documents";
 		}
 	}
-	res = fuse_main(args.argc, args.argv, &ifuse_oper, NULL);
+	res = fuse_main(args.argc, args.argv, oper, NULL);
 
 leave_err:
 	if (house_arrest) {
