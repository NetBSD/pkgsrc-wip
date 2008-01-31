# $NetBSD: Makefile,v 1.6 2008/01/31 17:07:40 bsadewitz Exp $

DISTNAME=	xorg-server-1.4-20080130
PKGNAME=	modular-xorg-server-1.4.20080130
CATEGORIES=	x11
MASTER_SITES=	http://www.netbsd.org/~bjs/distfiles/

SPECIAL_PERMS+=	bin/Xorg ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	bjs@NetBSD.org
COMMENT=	Xorg X11 Server from modular X.org X11

BUILD_DEPENDS+=	xorg-util-macros-[0-9]*:../../devel/xorg-util-macros

OWN_DIRS+=		${VARBASE}/db/xkb

WRKSRC=			${WRKDIR}/xserver-1.4-20080130

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake patch perl autoconf automake
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-xkb-output=${VARBASE}/db/xkb
CONFIGURE_ARGS+=	--with-dri-driver-path=${LOCALBASE}/lib/dri
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--disable-dmx

PKG_SUPPORTED_OPTIONS=	dri
PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server
PKG_OPTIONS_LEGACY_OPTS=glx:dri
.include "../../mk/bsd.options.mk"

### XXX configure.ac is now patched to handle __GLX_ALIGN64, but I'm not
###	removing this just yet.  If you see that defined twice, that's
###	why.
###
.if !empty(PKG_OPTIONS:Mdri)
GLX_DEFINES+=		-DPTHREADS	# Sure, why not?  No -lpthread link.
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		MesaLib-7.0.3-rc1.tar.gz
SITES.MesaLib-7.0.3-rc1.tar.gz= http://www.mesa3d.org/beta/
MESA_SRC=		${WRKDIR}/Mesa-7.0.3-rc1
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC}
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha"
GLX_DEFINES+=		-D__GLX_ALIGN64
.endif
CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
# glcore.h and dri_interface.h shipped with *proto are older than
# those in Mesa-7.0.3-rc1. Either patch them or trick the build into using
# the newer ones.
#BUILDLINK_API_DEPENDS.glproto+= glproto>=1.4.9
#BUILDLINK_API_DEPENDS.xf86driproto+= xf86driproto>=2.0.3nb1
PLIST_SUBST+=		USE_DRI=""
.else
CONFIGURE_ARGS+=	--disable-glx
PLIST_SUBST+=		USE_DRI="@comment "
.endif

CONFIGURE_ENV+=	APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5

BUILD_DEFS+=		VARBASE

DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3
BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.4
BUILDLINK_API_DEPENDS.libxf86dga+=	libXxf86dga>=1.0.2
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.1
BUILDLINK_API_DEPENDS.xf86dgaproto+=	xf86dgaproto>=2.0.2

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-extract:
	${CP} ${FILESDIR}/modeline2c.awk ${WRKSRC}/hw/xfree86/common && \
# XXX repugnant malkludgery
	${LN} -s ${WRKSRC:Q}/../Mesa-7.0.3-rc1/include/GL ${WRKSRC:Q}/GL/glx/GL

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.if empty(PKG_OPTIONS:Mdri)
# for GLX we already have the Mesa source
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
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
