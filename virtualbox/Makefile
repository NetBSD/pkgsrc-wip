# $NetBSD$

DISTNAME=	virtualbox-ose-5.0.16
PKGNAME=	${DISTNAME:C/-ose//}
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${PKGVERSION_NOREV}/ \
	http://tmp.chruetertee.ch/ \
	http://disasterarea.chruetertee.ch/ \
	http://download.virtualbox.org/virtualbox/${VBOX_GUEST_VER}/:guestadditions
DISTFILES=	VirtualBox-${PKGVERSION_NOREV}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY=	VirtualBox-${PKGVERSION_NOREV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	kbuild-[0-9]*:../../devel/kbuild
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

USE_TOOLS+=	gtar pkg-config bison flex perl

WRKSRC=		${WRKDIR}/VirtualBox-${PKGVERSION_NOREV}

HAS_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
# Required by Linux build
BUILD_DEPENDS+=	makeself-[0-9]*:../../archivers/makeself
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Adjust paths for pkgsrc
SUBST_STAGE.paths=	pre-configure
#SUBST_STAGE.paths=	post-build
SUBST_FILES.paths+=	configure
SUBST_SED.paths+=	-e 's!^INCCRYPTO=.*!INCCRYPTO="-I${BUILDLINK_PREFIX.openssl}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBCRYPTO=.*!LIBCRYPTO="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"!g'
SUBST_SED.paths+=	-e 's!^INCX11=.*!INCX11="-I${X11BASE}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBX11=.*!LIBX11="${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib -lXext -lX11"!g'
SUBST_SED.paths+=	-e 's!^INCZ=.*!INCZ="-I${BUILDLINK_PREFIX.zlib}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBZ=.*!LIBZ="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -L${BUILDLINK_PREFIX.zlib}/lib -lz"!g'
.if ${OPSYS} == "Linux"
.include "../../sysutils/lvm2/buildlink3.mk"
SUBST_SED.paths+=	-e 's!^INCDEVMAPPER=.*!INCDEVMAPPER="-I${BUILDLINK_PREFIX.lvm2}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBDEVMAPPER=.*!LIBDEVMAPPER="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lvm2}/lib -L${BUILDLINK_PREFIX.lvm2}/lib -ldevmapper"!g'
.include "../../sysutils/libcap/buildlink3.mk"
SUBST_SED.paths+=	-e 's!^INCCAP=.*!INCCAP="-I${BUILDLINK_PREFIX.libcap}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBCAP=.*!LIBCAP="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libcap}/lib -L${BUILDLINK_PREFIX.libcap}/lib -lcap"!g'
.endif
SUBST_SED.paths+=	-e 's!^INCCURL=.*!INCCURL="-I${BUILDLINK_PREFIX.curl}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBCURL=.*!LIBCURL="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib -L${BUILDLINK_PREFIX.curl}/lib -lcurl"!g'
SUBST_SED.paths+=	-e 's!^INCPULSE=.*!INCPULSE="-I${BUILDLINK_PREFIX.pulseaudio}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBPULSE=.*!LIBPULSE="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib -L${BUILDLINK_PREFIX.pulseaudio}/lib"!g'
SUBST_SED.paths+=	-e 's!^INCPNG=.*!INCPNG="-I${BUILDLINK_PREFIX.png}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBPNG=.*!LIBPNG="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.png}/lib -L${BUILDLINK_PREFIX.png}/lib"!g'
SUBST_SED.paths+=	-e 's!^INCVPX=.*!INCVPX="-I${BUILDLINK_PREFIX.libvpx}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBVPX=.*!LIBVPX="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libvpx}/lib -L${BUILDLINK_PREFIX.libvpx}/lib -lvpx"!g'
# These paths are used as a shell enumeration to check
SUBST_SED.paths+=	-e 's!^PYTHONDIR=.*!PYTHONDIR="${PREFIX}"!g'
SUBST_SED.paths+=	-e 's!^QT4DIR=.*!QT4DIR="${QTDIR}"!g'
# Set proper path of Python libs under ${PREFIX}/lib..
SUBST_SED.paths+=	-e 's!lib/x86_64-linux-gnu lib/i386-linux-gnu lib64 lib/64 lib!lib!g'
# Use pkgsrc provided Python version
SUBST_SED.paths+=	-e 's!SUPPYTHONLIBS=.*!SUPPYTHONLIBS="python${PYVERSSUFFIX}"!g'
# Add needed rpath for testing execution of an application linked with libpython
SUBST_SED.paths+=	-e 's!PYTHONLIBRPATH=.*!PYTHONLIBRPATH="${COMPILER_RPATH_FLAG}${PREFIX}/lib"!g'

VBLIBDIR=	${PREFIX}/lib/virtualbox

KMK_ENV_VARS+=	KBUILD_PATH=${WRKSRC}/kBuild
KMK_ENV_VARS+=	KBUILD_LIB_SEARCH_ROOTS="/ /usr/ ${X11BASE}/ ${PREFIX}/"
# Multiple jobs tend to be broken
KMK_FLAGS+=	-j1

pre-configure:
	${RUN} ${ECHO} "VBOX_GCC_OPT=${CXXFLAGS}" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_WITH_ORIGIN:=" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_WITH_RUNPATH:=${VBLIBDIR}" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_PATH_APP_PRIVATE_ARCH:=${VBLIBDIR}" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_PATH_APP_PRIVATE:=${VBLIBDIR}" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_WITH_TESTCASES=" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_WITH_TESTSUITE:=" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_JAVA_HOME:=${JAVA_HOME}" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_USE_SYSTEM_XORG_HEADERS:=1" >> ${WRKSRC}/LocalConfig.kmk

do-build:
	${RUN} cd ${WRKSRC} && . ./env.sh && ${KMK_ENV_VARS} kmk ${KMK_FLAGS}

do-install:
	${RUN} cd ${WRKSRC} && . ./env.sh && kmk install

.include "../../mk/java-vm.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
