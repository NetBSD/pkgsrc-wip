# $NetBSD$

DISTNAME=	fltk-1.4.x
CATEGORIES=	x11
GITHUB_TAG=	abc8f4158f2171884e055a2ca4b234655220c26e
MASTER_SITES=	https://github.com/fltk/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake nroff
TEST_TARGET=		test

# ------------------------------------------------------
# Options

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk14
PKG_SUPPORTED_OPTIONS=	cairo opengl pango
PKG_SUGGESTED_OPTIONS=	opengl pango
PLIST_VARS+=		opengl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcairo)
.  include "../../graphics/cairo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cairo
.else
CONFIGURE_ARGS+=	--disable-cairo
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.if ${OPSYS} != "Darwin"
.  include "../../graphics/Mesa/buildlink3.mk"
.endif
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=		yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

.if !empty(PKG_OPTIONS:Mpango)
.  include "../../devel/pango/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pango
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

# ------------------------------------------------------

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes

PLIST_VARS+=		cs	# case-sensitive
.if !exists(./descr) && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-links
PLIST.cs=		yes
.endif

CONFIGURE_ARGS+=	--enable-shared
# Use pkgsrc versions, not package's bundled versions.
CONFIGURE_ARGS+=	--disable-localjpeg --disable-localzlib --disable-localpng

post-extract:
	cd ${WRKSRC} && autoconf

pre-configure:
	cd ${WRKSRC} && ${GMAKE} ${MAKE_FLAGS} clean

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
