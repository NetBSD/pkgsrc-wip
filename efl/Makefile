# $NetBSD: Makefile,v 0.3 2018/09/07 20:03:10 andyb Exp $

DISTNAME=	efl-1.28.1
CATEGORIES=	x11
MASTER_SITES=	https://download.enlightenment.org/rel/libs/efl/
EXTRACT_SUFX=	.tar.xz
MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Enlightenment foundation libraries
# efl/COPYING lists the licenses for each contained library.
LICENSE=	gnu-lgpl-v2.1

EFL_LIBRARY_PATH=	${WRKSRC}/output/src/lib

EFLLIBS=	ecore ecore_audio ecore_con ecore_evas ecore_file
EFLLIBS+=	ecore_imf ecore_imf_evas ecore_input ecore_input_evas
EFLLIBS+=	ecore_ipc ecore_x ector edje eet efl efreet
EFLLIBS+=	eina eio eldbus elementary elua elput embryo emile emotion
EFLLIBS+=	eo eolian ephysics ethumb ethumb_client evas evil

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
SUBST_SED.xdg=		-e 's,/usr/share:/usr/local/share,${PREFIX}/share,g'
SUBST_SED.xdg+=		-e 's,/etc/xdg,${PKG_SYSCONFDIR}/xdg,g'

REPLACE_PYTHON+=	src/bin/exactness/exactness_play.in
REPLACE_PYTHON+=	src/bin/exactness/exactness_record.in

TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PLIST_VARS+=	linux

.if ${OPSYS} != "Linux"
MESON_ARGS+=		-Dsystemd=false
MESON_ARGS+=		-Dv4l2=false
MESON_ARGS+=		-Deeze=false
MESON_ARGS+=		-Dinput=false
.else
PLIST.linux=		yes
EFLLIBS+=		eeze
.endif
.for e in ${EFLLIBS}
EFL_LIBRARY_PATH:=	${EFL_LIBRARY_PATH}:${WRKSRC}/output/src/lib/${e}
.endfor

MAKE_ENV+=	LD_LIBRARY_PATH=${EFL_LIBRARY_PATH}


MESON_ARGS+=	-Dbuild-examples=false
MESON_ARGS+=	-Dphysics=true
MESON_ARGS+=	-Dlibmount=false
#MESON_ARGS+=	-Dmount-path=/usr/bin/mount
#MESON_ARGS+=	-Dunmount-path=/usr/bin/umount
#MESON_ARGS+=	-Deject-path=/usr/bin/eject

LUA_VERSIONS_ACCEPTED=	52 51
.include "../../lang/lua/luaversion.mk"
MESON_ARGS+= 	-Dlua-interpreter=lua

.if ${X11_TYPE} != "modular"

SUBST_CLASSES+=			fix-options
SUBST_MESSAGE.fix-options=	Fixing meson opengl options
SUBST_STAGE.fix-options=	pre-configure
SUBST_FILES.fix-options=	meson_options.txt
SUBST_SED.fix-options=		-e "s|'es-egl', 'none'|'es-egl', 'base', 'none'|g"
MESON_ARGS+=			-Dopengl=base

.else

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"

.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.include "../../wip/libinput/buildlink3.mk"
.endif
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.40.0
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
