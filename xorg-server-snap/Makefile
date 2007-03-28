# $NetBSD: Makefile,v 1.1 2007/03/28 19:21:49 bsadewitz Exp $

DISTNAME=	xorg-server-1.2.99.903
PKGNAME=	modular-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	blair.sadewitz@gmail.com
COMMENT=	Xorg X11 Server from modular X.org X11

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		gmake perl pkg-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-dri=yes
CONFIGURE_ARGS+=	--disable-xvfb
CONFIGURE_ARGS+=	--disable-xnest
CONFIGURE_ARGS+=	--disable-xprint
CONFIGURE_ARGS+=	--disable-dmx

PTHREAD_AUTO_VARS=	yes # XXX When I set GLX_CFLAGS, et. al, the build
			    # broke due to quoting problems (or something else),
			    # I think.

PKG_SUPPORTED_OPTIONS=	glx
PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mglx)

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		MesaLib-6.5.2.tar.bz2
SITES.MesaLib-6.5.2.tar.bz2= ${MASTER_SITE_SOURCEFORGE:=mesa3d/}
MESA_SRC=		${WRKDIR}/Mesa-6.5.2
CONFIGURE_ARGS+=	--enable-aiglx=yes
CONFIGURE_ARGS+=	--enable-glx=yes
CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC}

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha"

GLX_DEFINES+=		-D__GLX_ALIGN64
.endif

CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
# glcore.h and dri_interface.h shipped with *proto are older than
# those in Mesa-6.5.2. Either patch them or trick the build into using
# the newer ones.
#BUILDLINK_API_DEPENDS.glproto+= glproto>=1.4.8nb1
#BUILDLINK_API_DEPENDS.xf86driproto+= xf86driproto>=2.0.3nb1

post-extract:
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL
PLIST_SUBST+=		GLX=""
.else

CONFIGURE_ARGS+=	--disable-glx
PLIST_SUBST+=		GLX="@comment "
.endif

BUILD_DEFS+=		VARBASE
# -wip
#DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

DEPENDS+=		xkbdata-[0-9]*:../../x11/xkbdata

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3



.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk" # Need BUILDLINK_TRANSFORM or else
				         # build breaks with ncurses.
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.if empty(PKG_OPTIONS:Mglx)
# for GLX we already have the Mesa source

.include "../../graphics/MesaLib/buildlink3.mk"
.endif

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
#.include "../../x11/libXmu/buildlink3.mk" # FreeBSD includes both
#.include "../../x11/libXpm/buildlink3.mk" # of these packages.  Why?
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
