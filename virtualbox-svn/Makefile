# $NetBSD$


SVN_REPOSITORIES=	mirror
SVN_REPO.mirror=	https://www.virtualbox.org/svn/vbox

PKGNAME=	virtualbox-0.0.0
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
BUILD_DEPENDS+=	kbuild-[0-9]*:../../devel/kbuild
BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

USE_TOOLS+=	gtar pkg-config bison flex perl

WRKSRC=		${WRKDIR}/mirror/trunk

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
SUBST_FILES.paths+=	configure
.if ${OPSYS} == "Linux"
.include "../../sysutils/lvm2/buildlink3.mk"
SUBST_SED.paths+=	-e 's!^INCDEVMAPPER=.*!INCDEVMAPPER="-I${BUILDLINK_PREFIX.lvm2}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBDEVMAPPER=.*!LIBDEVMAPPER="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lvm2}/lib -L${BUILDLINK_PREFIX.lvm2}/lib -ldevmapper"!g'
.include "../../sysutils/libcap/buildlink3.mk"
SUBST_SED.paths+=	-e 's!^INCCAP=.*!INCCAP="-I${BUILDLINK_PREFIX.libcap}/include"!g'
SUBST_SED.paths+=	-e 's!^LIBCAP=.*!LIBCAP="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libcap}/lib -L${BUILDLINK_PREFIX.libcap}/lib -lcap"!g'
.endif

VBLIBDIR=	${PREFIX}/lib/virtualbox

KMK_ENV_VARS+=	KBUILD_PATH=${WRKSRC}/kBuild
KMK_ENV_VARS+=	KBUILD_LIB_SEARCH_ROOTS="/ /usr/ ${X11BASE}/ ${PREFIX}/"
# Multiple jobs tend to be broken
KMK_FLAGS+=	-j${MAKE_JOBS}

.if ${OPSYS} == "NetBSD"
BUILDLINK_PASSTHRU_DIRS+=	/usr/src
.endif

CONFIGURE_ARGS+=	--with-kbuild=${PREFIX}/share/kBuild/
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
CONFIGURE_ARGS+=	--with-openssl-incset="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ARGS+=	--with-openssl-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib -L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"
CONFIGURE_ARGS+=	--with-curl-incset="-I${BUILDLINK_PREFIX.curl}/include"
CONFIGURE_ARGS+=	--with-curl-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib -L${BUILDLINK_PREFIX.curl}/lib -lcurl"
CONFIGURE_ARGS+=	--with-zlib-incset="-I${BUILDLINK_PREFIX.zlib}/include"
CONFIGURE_ARGS+=	--with-zlib-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -L${BUILDLINK_PREFIX.zlib}/lib -lz"
CONFIGURE_ARGS+=	--with-x11-incset="-I${X11BASE}/include"
CONFIGURE_ARGS+=	--with-x11-libset="${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib -lXext -lX11"
CONFIGURE_ARGS+=	--with-pulse-incset="-I${BUILDLINK_PREFIX.pulseaudio}/include"
CONFIGURE_ARGS+=	--with-pulse-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib -L${BUILDLINK_PREFIX.pulseaudio}/lib"
CONFIGURE_ARGS+=	--with-png-incset="-I${BUILDLINK_PREFIX.png}/include"
CONFIGURE_ARGS+=	--with-png-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.png}/lib -L${BUILDLINK_PREFIX.png}/lib"
CONFIGURE_ARGS+=	--with-vpx-incset="-I${BUILDLINK_PREFIX.libvpx}/include"
CONFIGURE_ARGS+=	--with-vpx-libset="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libvpx}/lib -L${BUILDLINK_PREFIX.libvpx}/lib"
CONFIGURE_ARGS+=	--with-iasl=${PREFIX}/bin/iasl
CONFIGURE_ARGS+=	--with-python-dirset=${PREFIX}
CONFIGURE_ARGS+=	--with-python-linkextraset=${COMPILER_RPATH_FLAG}${PREFIX}/lib
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-makeself=${PREFIX}/bin/makeself
.endif

# Temporary option to get headless build functional first
CONFIGURE_ARGS+=	--build-headless

pre-configure:
	${RUN} ${ECHO} "VBOX_GCC_OPT=${CXXFLAGS}" >> ${WRKSRC}/LocalConfig.kmk
#	${RUN} ${ECHO} "VBOX_WITH_ORIGIN:=" >> ${WRKSRC}/LocalConfig.kmk
	${RUN} ${ECHO} "VBOX_WITH_RUNPATH:=${VBLIBDIR}:${PREFIX}/lib" >> ${WRKSRC}/LocalConfig.kmk
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

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
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
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
