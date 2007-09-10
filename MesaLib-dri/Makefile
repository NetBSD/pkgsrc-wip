# $NetBSD: Makefile,v 1.17 2007/09/10 05:01:38 bsadewitz Exp $

DISTNAME=	MesaLib-${MESA_VERSION}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mesa3d/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/xorg
COMMENT=	OpenGL library that renders using GLX or DRI

PATCH_SITES=	http://bahar.aydogan.net/~blair/
PATCHFILES=	mesalib-7.0-master.patch
PATCH_DIST_STRIP=	-p2

MESA_VERSION=	7.0.1

NO_CONFIGURE=	yes
USE_TOOLS+=	makedepend gmake
USE_LIBTOOL+=	yes

PKG_DESTDIR_SUPPORT=user-destdir

INSTALLATION_DIRS_FROM_PLIST=	yes

DRI_MODULE_DIR?=	lib/dri
BUILD_DEFS+=		DRI_MODULE_DIR
PLIST_SUBST+=		DRI_MODULE_DIR=${DRI_MODULE_DIR}

GL_HEADERS=	gl.h gl_mangle.h glext.h glx.h glx_mangle.h glxext.h
GL_HEADERS+=	osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h

WRKSRC=		${WRKDIR}/Mesa-${MESA_VERSION}

DRI_CFLAGS+=	-DPTHREADS -DUSE_XSHM  -fno-strict-aliasing
CFLAGS.NetBSD+=-D_REENTRANT
PKGSRC_PICFLAGS=-fPIC -DPIC

.include "subst.mk"
.include "options.mk"

CFLAGS+=	${DRI_CFLAGS}
MAKE_ENV+=	DRI_DIRS=${DRI_DRIVERS:M*:Q}
MAKE_ENV+=	DRI_MODULE_DIR=${DRI_MODULE_DIR:Q}
MAKE_ENV+=	PKGSRC_PICFLAGS=${PKGSRC_PICFLAGS:Q}
MAKE_ENV+=	SHELL=${TOOLS_SHELL:Q}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=	-fvisibility=hidden # Mostly for x86_64
.endif

post-extract:
	${CP}   ${WRKSRC}/configs/freebsd-dri ${WRKSRC}/configs/netbsd-dri
	${CP}	${WRKSRC}/configs/freebsd     ${WRKSRC}/configs/netbsd
	${CP}	${WRKSRC}/configs/freebsd-dri-x86 ${WRKSRC}/configs/netbsd-dri-x86
	${CP}	${WRKSRC}/configs/freebsd-dri-amd64 ${WRKSRC}/configs/netbsd-dri-amd64

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL
	for i in ${GL_HEADERS}; do \
	${INSTALL_DATA} ${WRKSRC}/include/GL/$$i ${DESTDIR}${PREFIX}/include/GL; done
	cd ${WRKSRC}/lib && \
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/${DRI_MODULE_DIR} && \
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/glx/x11/libGL.la ${DESTDIR}${PREFIX}/lib && \
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/glw/libGLw.la ${DESTDIR}${PREFIX}/lib

.if target(do-install)
. for d in ${DRI_DRIVERS} 
	${INSTALL_LIB} ${WRKSRC}/lib/${d}_dri.so ${DESTDIR}${PREFIX}/${DRI_MODULE_DIR}
. endfor
.endif

.include "../../textproc/expat/buildlink3.mk"

.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"

.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
