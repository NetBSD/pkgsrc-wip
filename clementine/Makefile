# $NetBSD$

GITHUB_PROJECT=	Clementine
DISTNAME=	1.3.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=clementine-player/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	weabot@protonmail.com
HOMEPAGE=	https://www.clementine-player.org/
COMMENT=	Cross-platform music player inspired by Amarok 1.4
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	3rdparty/libprojectm/libprojectM.pc.in

CFLAGS+=	-Wno-inconsistent-missing-override \
		-Wno-unused-variable \
		-Wno-unused-function

CMAKE_ARGS+=	-DENABLE_SPOTIFY_BLOB=OFF \
		-DCRYPTOPP_LIBS=${LOCALBASE}/lib/libcryptopp.so \
	     	-DCRYPTOPP_INCLUDEDIR=${LOCALBASE}/include/cryptopp \
	     	-DCRYPTOPP_LIBDIR=${LOCALBASE}/lib \
	     	-DCRYPTOPP_LDFLAGS=-lcryptopp \
	     	-DCRYPTOPP_LIBRARIES=cryptopp \
	     	-DCRYPTOPP_LIBRARY_DIRS=${LOCALBASE}/lib \
	     	-DCRYPTOPP_cryptopp_INCLUDEDIR=${LOCALBASE}/include/cryptopp \
	     	-DCRYPTOPP_cryptopp_LIBDIR=${LOCALBASE}/lib \
	     	-DCRYPTOPP_FOUND=1 \
		-DENABLE_DBUS=ON \
		-DBUILD_WERROR=OFF


BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake \
		pkgconf>=0.9.10:../../devel/pkgconf

DEPENDS+=	qt4-tiff>=4.5.0:../../x11/qt4-tiff \
		qt4-sqlite3>=4.5.0:../../x11/qt4-sqlite3 \
		gst-plugins1-cdparanoia>=1.4.0:../../audio/gst-plugins1-cdparanoia \
		gst-plugins1-oss>=1.4.0:../../audio/gst-plugins1-oss \
		gst-plugins1-faac>=1.4.0:../../audio/gst-plugins1-faac \
		gst-plugins1-faad>=1.4.0:../../audio/gst-plugins1-faad \
		gst-plugins1-flac>=1.4.0:../../audio/gst-plugins1-flac \
		gst-plugins1-gio>=1.4.0:../../sysutils/gst-plugins1-gio \
		gst-plugins1-lame>=1.4.0:../../audio/gst-plugins1-lame \
		gst-plugins1-mpg123>=1.4.0:../../audio/gst-plugins1-mpg123 \
		gst-plugins1-opus>=1.4.0:../../audio/gst-plugins1-opus \
		gst-plugins1-twolame>=1.4.0:../../audio/gst-plugins1-twolame \
		gst-plugins1-vorbis>=1.4.0:../../audio/gst-plugins1-vorbis \
		gst-plugins1-ogg>=1.4.0:../../multimedia/gst-plugins1-ogg


.include "../../audio/chromaprint/buildlink3.mk"
.include "../libechonest/buildlink3.mk" # Will be moved to audio/
.include "../../audio/taglib/buildlink3.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/sparsehash/buildlink3.mk" # Flagged as optional but clementine refuses to build without it.

.include "../../graphics/glew/buildlink3.mk"

.include "../../math/fftw/buildlink3.mk"

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-ugly/buildlink3.mk"

.include "../../security/crypto++/buildlink3.mk" # Said to be optional on github but CMake requires it
.include "../../security/qca2/buildlink3.mk"

.include "../../textproc/libxml2/buildlink3.mk"

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
