$NetBSD$

support NetBSD

--- libs/fst/fstapi.cc.orig
+++ libs/fst/fstapi.cc
@@ -3607,6 +3607,7 @@ static int fstReaderRecreateHierFile(struct fstReaderContext *xc)
             fflush(xc->f);
 #endif
             zfd = dup(fileno(xc->f));
+	    lseek(zfd, ftell(xc->f), SEEK_SET);
             zhandle = gzdopen(zfd, "rb");
             if (!zhandle) {
                 close(zfd);
@@ -4272,6 +4273,7 @@ int fstReaderInit(struct fstReaderContext *xc)
 #endif
 
         zfd = dup(fileno(xc->f));
+	lseek(zfd, ftell(xc->f), SEEK_SET);
         zhandle = gzdopen(zfd, "rb");
         if (zhandle) {
             for (offpnt = 0; offpnt < uclen; offpnt += FST_GZIO_LEN) {
