# $NetBSD: Makefile,v 0.3 2018/09/07 20:03:10 andyb Exp $

DISTNAME=	efl-1.24.1
CATEGORIES=	x11
MASTER_SITES=	https://download.enlightenment.org/rel/libs/efl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Enlightenment foundation libraries
LICENSE=	2-clause-bsd

EFL_LIBRARY_PATH=	${WRKSRC}/output/src/lib

EFLLIBS=	ecore ecore_audio ecore_avahi ecore_con ecore_evas
EFLLIBS+=	ecore_file ecore_imf ecore_imf_evas ecore_input ecore_input_evas
EFLLIBS+=	ecore_ipc ecore_sdl ecore_x ector edje eet efl efreet
EFLLIBS+=	eina eio eldbus elementary elua embryo emile emotion
EFLLIBS+=	eo eolian ephysics ethumb ethumb_client evas evil

.for e in ${EFLLIBS}
EFL_LIBRARY_PATH:=	${EFL_LIBRARY_PATH}:${WRKSRC}/output/src/lib/${e}
.endfor

MAKE_ENV+=	LD_LIBRARY_PATH=${EFL_LIBRARY_PATH}

MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Deeze=false
MESON_ARGS+=	-Dpulseaudio=false
MESON_ARGS+=	-Dbuild-tests=false
MESON_ARGS+=	-Dbuild-examples=false
MESON_ARGS+=	-Dphysics=true
MESON_ARGS+=	-Davahi=true
MESON_ARGS+=	-Dsdl=true

USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config
ICON_THEMES=		yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing exactness library paths.
SUBST_FILES.fix-paths=		src/bin/exactness/*.in
SUBST_SED.fix-paths=		-e 's,@EXACTNESS_PLAY_PRELOAD_PATH@,${PREFIX}/lib/libexactness_play.so.${PKGVERSION},g'
SUBST_SED.fix-paths+=		-e 's,@EXACTNESS_RECORD_PRELOAD_PATH@,${PREFIX}/lib/libexactness_record.so.${PKGVERSION},g'

SUBST_CLASSES+=		xdg
SUBST_MESSAGE.xdg=	Fixing XDG_DATA_DIRS and XDG_CONFIG_DIRS
SUBST_STAGE.xdg=	pre-configure
SUBST_FILES.xdg=	src/lib/efreet/efreet_base.c
SUBST_SED.xdg=		-e 's,/usr/share:/usr/local/share,${PREFIX}/share,'
SUBST_SED.xdg+=		-e 's,/etc/xdg,${PKG_SYSCONFDIR}/xdg,'

REPLACE_PYTHON+=	src/bin/exactness/exactness_play.in
REPLACE_PYTHON+=	src/bin/exactness/exactness_record.in

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
