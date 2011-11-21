# $NetBSD: Makefile,v 1.14 2011/11/21 19:08:56 absd Exp $
#

.include "../../wip/kaffe/Makefile.common"

PKGNAME=    ${DISTNAME:S/kaffe/kaffe-x11/}
PKGREVISION=	3

COMMENT+=   (AWT support through X11)

CONFIGURE_ARGS+=  --with-kaffe-x-awt
CONFIGURE_ARGS+=  --enable-gtk-peer
CONFIGURE_ARGS+=  --with-x

BUILD_DIRS=	${WRKSRC}/config
BUILD_DIRS+=	${WRKSRC}/libraries/javalib
BUILD_DIRS+=	${WRKSRC}/include
BUILD_DIRS+=	${WRKSRC}/replace
BUILD_DIRS+=	${WRKSRC}/libltdl
BUILD_DIRS+=	${WRKSRC}/kaffe/kaffevm
BUILD_DIRS+=	${WRKSRC}/libraries/clib/classpath
BUILD_DIRS+=	${WRKSRC}/libraries/clib/awt
BUILD_DIRS+=	${WRKSRC}/libraries/javalib/external/classpath/native/jni/gtk-peer
BUILD_DIRS+=	${WRKSRC}/libraries/javalib/external/classpath/native/jawt
INSTALL_DIRS=	${WRKSRC}/libraries/clib/awt
INSTALL_DIRS+=	${WRKSRC}/libraries/javalib/external/classpath/native/jni/gtk-peer
INSTALL_DIRS+=	${WRKSRC}/libraries/javalib/external/classpath/native/jawt

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} BUILD_ENVIRONMENT

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/kaffe/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
