$NetBSD$

--- src/fellow_io_threads.c.orig	2023-02-06 07:10:31.000000000 +0000
+++ src/fellow_io_threads.c
@@ -233,7 +233,11 @@ fellow_io_thread_task(struct worker *wrk
 		r = pwrite(ctx->fd, req->buf, req->bytes, req->off);
 		break;
 	case FIOT_FALLOCATE:
+#if defined(__NetBSD__)
+		r = posix_fallocate(ctx->fd, req->off, (off_t)req->bytes);
+#else
 		r = fallocate(ctx->fd, req->mode, req->off, (off_t)req->bytes);
+#endif
 		break;
 	default:
 		WRONG("cmd in io_thread_task");
