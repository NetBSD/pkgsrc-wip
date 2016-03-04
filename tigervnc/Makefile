# $NetBSD$

DISTNAME=	tigervnc-1.6.0
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=TigerVNC/}

COMMENT=	VNC server and client with TLS, RandR, and shared clipboard
HOMEPAGE=	http://tigervnc.org/
MAINTAINER=	dominik.muth@gmx.de
LICENSE=	gnu-gpl-v2
GITHUB_PROJECT=	TigerVNC
GITHUB_TAG=	v${PKGVERSION_NOREV}

TIGERVNC_XORGVERSION=	1.18.1
DISTFILE_XORG=	xorg-server-${TIGERVNC_XORGVERSION}.tar.gz
DISTFILES=	${DEFAULT_DISTFILES} ${DISTFILE_XORG}
SITES.${DISTFILE_XORG}= ${MASTER_SITE_XORG:=xserver/}

CONFLICTS=	vnc-[0-9]* vncviewer-[0-9]* tightvnc-[0-9]*

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES= 	c c++
USE_TOOLS+=	autoconf automake autoreconf gmake msgfmt patch perl:run pkg-config tar

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && \
		${TAR} zxf ${DISTDIR}/${DEFAULT_DISTFILES}
	cd ${WRKSRC} && \
		${TAR} zxf ${DISTDIR}/xorg-server-${TIGERVNC_XORGVERSION}.tar.gz
	cd ${WRKSRC} && \
		cp -R xorg-server-${TIGERVNC_XORGVERSION}/* ${DISTNAME}/unix/xserver/
	cd ${WRKSRC}/${DISTNAME}/unix/xserver && \
		${PATCH} -Np1 -z __shipped -i ../xserver117.patch

CONFIGURE_DIRS=	${DISTNAME}
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

pre-configure:
	cd ${WRKSRC}/${DISTNAME}/unix/xserver && \
		autoreconf -fiv
	cd ${WRKSRC}/${DISTNAME}/unix/xserver && \
		env ${CONFIGURE_ENV} \
			PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} \
			--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR} \
			--without-dtrace --with-pic \
			--disable-static --disable-unit-tests \
			--disable-devel-docs \
			--disable-selective-werror \
			--disable-xorg --disable-xnest --disable-xvfb --disable-dmx \
			--disable-xwin --disable-xephyr --disable-kdrive --disable-xwayland \
			--disable-config-hal --disable-config-udev \
			--disable-dri --disable-dri2 --disable-dri3 --disable-glx

# BUILD_MAKE_FLAGS+=	-j8

BUILD_DIRS=	${DISTNAME} ${DISTNAME}/unix/xserver

INSTALL_DIRS=	${DISTNAME} ${DISTNAME}/unix/xserver/hw/vnc

post-install:
	mv ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	rmdir ${DESTDIR}${PREFIX}/share/man/man1
	rmdir ${DESTDIR}${PREFIX}/share/man

DEPENDS+=	xauth-[0-9]*:../../x11/xauth
DEPENDS+=	xkbcomp-[0-9]*:../../x11/xkbcomp

PREFER_PKGSRC=	presentproto randrproto

.include	"../../mk/jpeg.buildlink3.mk"

.include	"../../x11/bigreqsproto/buildlink3.mk"
.include	"../../x11/compositeproto/buildlink3.mk"
.include	"../../x11/damageproto/buildlink3.mk"
.include	"../../x11/fltk13/buildlink3.mk"
.include	"../../fonts/font-util/buildlink3.mk"
.include	"../../security/gnutls/buildlink3.mk"
.include	"../../x11/libXdamage/buildlink3.mk"
.include	"../../x11/libXfont/buildlink3.mk"
.include	"../../x11/libXtst/buildlink3.mk"
.include	"../../security/libgcrypt/buildlink3.mk"
.include	"../../security/openpam/buildlink3.mk"
.include	"../../x11/pixman/buildlink3.mk"
.include	"../../graphics/png/buildlink3.mk"
.include	"../../x11/presentproto/buildlink3.mk"
.include	"../../x11/randrproto/buildlink3.mk"
.include	"../../x11/resourceproto/buildlink3.mk"
.include	"../../x11/scrnsaverproto/buildlink3.mk"
.include	"../../x11/videoproto/buildlink3.mk"
.include	"../../x11/xcmiscproto/buildlink3.mk"
.include	"../../x11/xf86vidmodeproto/buildlink3.mk"
.include	"../../x11/xkeyboard-config/buildlink3.mk"
.include	"../../devel/xorg-util-macros/buildlink3.mk"
.include	"../../x11/xproto/buildlink3.mk"
.include	"../../x11/xtrans/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
