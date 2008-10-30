# $NetBSD: gnu-configure.mk,v 1.1.1.1 2008/10/30 21:07:21 bsadewitz Exp $
#

MESA_PACKAGES=		gl-osmesa glu glut glw

.if "${MESA_PACKAGES:M${MESA_PACKAGE}}" == ""
PKG_FAIL_REASON=	"Invalid value for MESA_PACKAGE."
.endif

CONFIGURE_ARGS+=	--enable-${MESA_PACKAGES:M${MESA_PACKAGE}}
CONFIGURE_ARGS+=	${MESA_PACKAGES:N${MESA_PACKAGE}:@p@--disable-${p}@}

# XXX TODO

CONFIGURE_ARGS+=	--disable-ttm-api
CONFIGURE_ARGS+=	--disable-xcb
CONFIGURE_ARGS+=	--disable-selinux
CONFIGURE_ARGS+=	--with-demos=""
