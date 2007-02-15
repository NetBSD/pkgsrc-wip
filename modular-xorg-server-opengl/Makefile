# $NetBSD: Makefile,v 1.3 2007/02/15 06:02:33 bsadewitz Exp $

DISTNAME=	xorg-server-1.2.0
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

SPECIAL_PERMS+=	bin/Xorg ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	blair.sadewitz@gmail.com
COMMENT=	Xorg X11 Server from modular X.org X11 with OpenGL built-in

MESA_VERSION=	6.5.2
MESA_SRC?=	${WRKDIR}/Mesa-${MESA_VERSION}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MESALIB_DISTFILE}
DISTFILES+=	MesaLib-${MESA_VERSION}${EXTRACT_SUFX}
SITES.MesaLib-${MESA_VERSION}= ${MASTER_SITE_SOURCEFORGE:=mesa3d/}
#MESA_PATCHES=	af ag ah

GLX_DEFINES?=	# empty
GLX_LIBS=	# empty

GLX_OPTS?=	-O3 -ffast-math -frename-registers -mfpmath-sse \
		-maccumulate-outgoing-args

GLX_DEFINES+=	-DPTHREADS ${PTHREAD_CFLAGS}
GLX_DEFINES+=	-DUSE_XSHM ${GLX_OPTS}
GLX_LIBS+=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
.if (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "alpha") || \
	(${MACHINE_ARCH} == "sparc64")
GLX_DEFINES+=	-D__GLX_ALIGN64
.endif

XORG_XKBOUTPUTDIR?=	${VARBASE}/db/xkb
XORG_XKBDIR?=		${LOCALBASE}/share/xkb
XORG_XKBCOMPILED=	README.compiled

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-xkb-output=${XORG_XKBOUTPUTDIR:Q}
CONFIGURE_ARGS+=	--with-xkb-path=${XORG_XKBDIR:Q}
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-kbd_mode
CONFIGURE_ARGS+=	--enable-multibuffer
CONFIGURE_ARGS+=	--enable-fontcache
CONFIGURE_ARGS+=	--disable-dmx
CONFIGURE_ARGS+=	--disable-xprint
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-xsdl
CONFIGURE_ARGS+=	--disable-aiglx
CONFIGURE_ARGS+=	--disable-dependency-tracking

CONFIGURE_ARGS+=	--with-mesa-source=${MESA_SRC:Q}
CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
CONFIGURE_ENV+=		GLX_LIBS=${GLX_LIBS:M*:Q}

BUILD_DEFS+=		VARBASE

DEPENDS+=		xkbdata-[0-9]*:../../x11/xkbdata

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3

pre-configure:
	@${STEP_MSG} 'Fixing GL symlinks.'
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL

#post-install:
# install README.compiled somewhere.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontcacheproto/buildlink3.mk"
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

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
