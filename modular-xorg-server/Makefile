# $NetBSD: Makefile,v 1.5 2007/08/06 16:44:11 bsadewitz Exp $

DISTNAME=	xorg-server-1.3.99.0
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

SPECIAL_PERMS+=	bin/Xorg ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	blair.sadewitz@gmail.com
COMMENT=	Xorg X11 Server from modular X.org X11

DRI_MODULE_PATH?=	lib/xorg/modules/dri

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		perl
USE_TOOLS+=		automake
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--enable-dri

CONFIGURE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

PKG_SUPPORTED_OPTIONS=	dri dbus
PKG_SUGGESTED_OPTIONS=	dri

PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server
PKG_OPTIONS_LEGACY_OPTS=glx:dri
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdri)
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		MesaLib-7.0.1.tar.bz2
SITES.MesaLib-7.0.1.tar.bz2= ${MASTER_SITE_SOURCEFORGE:=mesa3d/}
MESA_SRC=		${WRKDIR}/Mesa-7.0.1
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC}
CONFIGURE_ARGS+=	--with-dri-drivers=${PREFIX:Q:=/${DRI_MODULE_PATH}}
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha"
GLX_DEFINES+=		-D__GLX_ALIGN64
.endif
CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
# glcore.h and dri_interface.h shipped with *proto are older than
# those in Mesa-6.5.2. Either patch them or trick the build into using
# the newer ones.
#BUILDLINK_API_DEPENDS.glproto+= glproto>=1.4.8nb1
#BUILDLINK_API_DEPENDS.xf86driproto+= xf86driproto>=2.0.3nb1
BUILDLINK_API_DEPENDS.inputroto+=	inputproto>=1.4.2
BUILDLINK_API_DEPENDS.compositeproto+=	compositeproto>=0.4
BUILDLINK_API_DEPENDS.libxkbui+=	libxkbui>=1.0.2
BUILDLINK_API_DEPENDS.pkg-config+=	pkg-config>=0.20

post-extract:
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL
	${CP} ${FILESDIR:Q}/glxbyteorder.h ${WRKSRC:Q}/GL/glx

pre-configure:
	cd ${WRKSRC} && autoreconf --install -v

PLIST_SUBST+=		GLX=""
.else
CONFIGURE_ARGS+=	--disable-glx
PLIST_SUBST+=		GLX="@comment "
.endif

BUILD_DEFS+=		VARBASE DRI_MODULE_PATH

# -wip
#DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config
DEPENDS+=		xkbdata-[0-9]*:../../x11/xkbdata
BUILD_DEPENDS+=		xorg-util-macros-[0-9]*:../../devel/xorg-util-macros

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.if empty(PKG_OPTIONS:Mdri)
# for GLX we already have the Mesa source
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-config-dbus
PLIST_SUBST+=		DBUS=""
.include "../../sysutils/dbus/buildlink3.mk"
.else
PLIST_SUBST+=		DBUS="@comment "
CONFIGURE_ARGS+=	--disable-config-dbus
.endif
.include "../../wip/pixman/buildlink3.mk"
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
.include "../../x11/liblbxutil/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
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

.include "../../mk/bsd.pkg.mk"
