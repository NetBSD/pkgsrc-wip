# $NetBSD: Makefile,v 1.21 2008/08/11 16:32:25 tnn2 Exp $

DISTNAME=	xorg-server-1.4.2
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11
#MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/
MASTER_SITES=	${MASTER_SITE_XORG:=xserver/}
EXTRACT_SUFX=	.tar.bz2

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		bjs@NetBSD.org
COMMENT=		Xorg X11 Server from modular X.org X11

# XXX this package should be upgraded to 1.1.6, I think.
BUILD_DEPENDS+=		xorg-util-macros>=1.1.5:../../devel/xorg-util-macros

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		gmake pkg-config autoconf automake

BUILD_DEFS+=		VARBASE
BUILD_DEFS_EFFECTS+=	XKB_OUTPUT_DIR

OWN_DIRS+=		${XKB_OUTPUT_DIR}
XKB_OUTPUT_DIR?=	${VARBASE}/db/xkb

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-xkb-output=${XKB_OUTPUT_DIR:Q}

WRKSRC=			${WRKDIR}/xorg-server-1.4.2

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-release-version=${PKGNAME}
CONFIGURE_ARGS+=	--with-vendor-name="The NetBSD Foundation"
CONFIGURE_ARGS+=	--with-vendor-name-short="pkgsrc"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-builder-addr="tech-x11@NetBSD.org"
CONFIGURE_ARGS+=	--with-os-vendor="The NetBSD Foundation"
.endif
CONFIGURE_ARGS+=	--with-os-name=${MACHINE_PLATFORM}
CONFIGURE_ARGS+=	--with-vendor-web="http://www.pkgsrc.org/"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-config-hal
CONFIGURE_ARGS+=	--disable-dmx
CONFIGURE_ARGS+=	--disable-xprint
CONFIGURE_ARGS+=	--disable-xwin
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS+=	--disable-kdrive-vesa
CONFIGURE_ARGS+=	--disable-xfake
CONFIGURE_ARGS+=	--disable-xsdl
CONFIGURE_ARGS+=	--disable-xfbdev
CONFIGURE_ARGS+=	--disable-kbd_mode	# deprecated
CONFIGURE_ARGS+=	--enable-builtin-fonts
CONFIGURE_ARGS+=	--enable-dri

CONFIGURE_ARGS+=	--with-int10=x86emu

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5

DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

BUILDLINK_API_DEPENDS.compositeproto+=	compositeproto>=0.4
BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.glproto+=		glproto>=1.4.8
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.1
###
### If we're using a 64-bit architecture, randrproto>=0.9.3 and
### xf86dgaproto>=2.0.3 are required.
###
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha"
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3
BUILDLINK_API_DEPENDS.xf86dgaproto+=	xf86dgaproto>=2.0.3
.endif
BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.4.2

post-extract: dri-post-extract
	${CP} ${FILESDIR}/modeline2c.awk ${WRKSRC}/hw/xfree86/common
#	${RM} -f ${WRKDIR}/Mesa-7.0.2/src/mesa/Makefile.orig
#	${RM} -f ${WRKDIR}/Mesa-7.0.2/docs/README.MINGW32.orig
#	${CP} ${FILESDIR}/prim_x86_gcc.h ${WRKSRC}/hw/xfree86/x86emu/x86emu/

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/trapproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -v -i -f

.include "../../mk/bsd.pkg.mk"
