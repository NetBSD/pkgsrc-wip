# $NetBSD$

DISTNAME=	fooyin-0.13.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=fooyin/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gourd753+pkgsrc@xenos5.net
HOMEPAGE=	https://github.com/fooyin/fooyin/
COMMENT=	Customisable music player
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		cmake pkg-config msgfmt
ICON_THEMES=		yes

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# doesn't build on NetBSD, and it's not useful anyway.
CMAKE_CONFIGURE_ARGS+=	"-DBUILD_ALSA=OFF"
.endif

BUILD_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

# get it to load its component libraries from the prefix
CMAKE_CONFIGURE_ARGS+=	"-DCMAKE_INSTALL_PREFIX=${PREFIX}"

post-build:
	# fix the rpath, the cmake forcibly overrides any attempts to do it
	patchelf --add-rpath "${PREFIX}/lib/fooyin" "./work/${DISTNAME}/cmake-pkgsrc-build/run/bin/fooyin"
	patchelf --add-rpath "${PREFIX}/lib/fooyin/plugins" "./work/${DISTNAME}/cmake-pkgsrc-build/run/bin/fooyin"

.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/ffmpeg9/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/qt6-qtimageformats/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../misc/kdsingleapplication/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libopenmpt/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../devel/qcoro/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdsingleapplication/buildlink3.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
