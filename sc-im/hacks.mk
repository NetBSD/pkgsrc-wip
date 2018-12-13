# $NetBSD$

# On Debian the build fails due to missing -ldl even though
# dlopen.buildlink3.mk is imported and USE_BUILTIN.dl resolves to 'yes'.
#
# It seems that DL_LIBS is populated from BUILDLINK_LIBS.dl but
# dlopen.builtin.mk assigns BUILDLINK_DLADD.dl which never ends up in DL_LIBS.

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}
