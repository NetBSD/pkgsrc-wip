# $NetBSD$
.if empty(ALT_BOOTDIR) || !exists(${ALT_BOOTDIR}/bin/java)
PKG_FAIL_REASON+=	"ALT_BOOTDIR not set or jdk missing."
PKG_FAIL_REASON+=	"Obtaining bootstrap binaries is currently left as an exercise for the reader."
.endif
