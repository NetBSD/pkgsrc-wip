# $NetBSD: Makefile,v 1.24 2017/04/30 01:21:55 ryoon Exp $

PKGNAME=	kodi-17.3
DISTNAME=	17.3-Krypton
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.kodi.tv/releases/source/

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	https://kodi.tv/
COMMENT=	Open source software media center
LICENSE=	gnu-gpl-v2

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

EXTRACT_USING=	gtar

WRKSRC=			${WRKDIR}/xbmc-xbmc-147cec4
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config automake autoconf autoreconf gawk cmake bash gmake
USE_LANGUAGES=		c c++
USE_JAVA=		build
USE_JAVA2=		yes

CMAKE_ARGS+=		-DJava_JAVA_EXECUTABLE=${JAVA_BINPREFIX}-java
CMAKE_ARGS+=		-DENABLE_INTERNAL_CROSSGUID=no

# internet download, problematic dependency for pkgsrc
CMAKE_ARGS+=		-DENABLE_DVDCSS=no

# XXX does not work?
CMAKE_ARGS+=		-DKODI_DEPENDSBUILD=0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # insists on < 3.0 as of 15.2

PLIST_SUBST+=		MACHINE_CPU=${MACHINE_CPU}

post-patch:
	${CP} -R ${FILESDIR}/project_cmake_scripts_netbsd/ \
		${WRKSRC}/project/cmake/scripts/netbsd
	${MKDIR} ${WRKSRC}/project/cmake/platform/netbsd
	${MKDIR} ${WRKSRC}/project/cmake/treedata/netbsd
	${CP} ${FILESDIR}/project_cmake_platform_netbsd_defines.txt \
		${WRKSRC}/project/cmake/platform/netbsd/defines.txt
	${CP} ${FILESDIR}/project_cmake_treedata_netbsd_subdirs.txt \
		${WRKSRC}/project/cmake/treedata/netbsd/subdirs.txt

do-build:
	${MKDIR} ${WRKDIR}/kodi-build
	cd ${WRKDIR}/kodi-build ; \
	${CMAKE} ${WRKSRC}/project/cmake ${CMAKE_ARGS} ; \
	${GMAKE}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
#.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/mysql55-client/buildlink3.mk"
#.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/crossguid/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../misc/libcec/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"


.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"
.include "../../multimedia/libva/buildlink3.mk"
.endif
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
.include "../../multimedia/libvdpau/buildlink3.mk"
.endif
.include "../../net/avahi/buildlink3.mk"
# builtin for now
#.include "../../net/libupnp/buildlink3.mk"
.include "../../archivers/libunrar/buildlink3.mk" # XXX new bl3
.include "../../multimedia/libdvdread/buildlink3.mk"

# XXX still builtin, still undefined reference
.include "../../wip/cpluff/buildlink3.mk"

.include "../../net/samba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
