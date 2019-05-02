# $NetBSD$

PKGNAME=	thedarkmod-2.07
DISTNAME=	thedarkmod.${PKGVERSION_NOREV}.src
CATEGORIES=	games
MASTER_SITES=	http://www.thedarkmod.com/sources/
EXTRACT_SUFX=	.7z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thedarkmod.com/main/
COMMENT=	First-person stealth video game inspired by the Thief series
LICENSE=	gnu-gpl-v3 AND modified-bsd

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c c++

GCC_REQD+=	8.0
PYTHON_VERSIONS_ACCEPTED=	27

CXXFLAGS+=	-DUSE_FILE32API

.include "../../mk/bsd.prefs.mk"

SCONS_ARGS+=	${_MAKE_JOBS}

.if ${MACHINE_ARCH} == "x86_64"
SCONS_ARGS+=	TARGET_ARCH="x64"
.elif ${MACHINE_ARCH} == "i386"
SCONS_ARGS+=	TARGET_ARCH="x86"
.endif

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
.for size in 16 32 48 64 128 256
INSTALLATION_DIRS+=	share/icons/hicolor/${size}x${size}/apps
.endfor
INSTALLATION_DIRS+=	share/thedarkmod

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	    CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	    LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q} VERBOSE=1 BUILD="release"
	${PREFIX}/bin/convert ${WRKSRC}/sys/win32/rc/res/darkmod.ico[5] \
	    ${WRKDIR}/tdm-256.png
	${PREFIX}/bin/convert ${WRKSRC}/tdm_update/tdm_package/darkmod.ico[4] \
	    ${WRKDIR}/tdm-128.png
	${PREFIX}/bin/convert ${WRKSRC}/tdm_update/tdm_package/darkmod.ico[3] \
	    ${WRKDIR}/tdm-64.png
	${PREFIX}/bin/convert ${WRKSRC}/tdm_update/tdm_package/darkmod.ico[2] \
	    ${WRKDIR}/tdm-48.png
	${PREFIX}/bin/convert ${WRKSRC}/tdm_update/tdm_package/darkmod.ico[1] \
	    ${WRKDIR}/tdm-32.png
	${PREFIX}/bin/convert ${WRKSRC}/tdm_update/tdm_package/darkmod.ico[0] \
	    ${WRKDIR}/tdm-16.png
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/thedarkmod.sh.in > \
	    ${WRKDIR}/thedarkmod.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/thedarkmod.sh ${DESTDIR}${PREFIX}/bin/thedarkmod
	${INSTALL_PROGRAM} ${WRKSRC}/thedarkmod ${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${FILESDIR}/thedarkmod.desktop ${DESTDIR}${PREFIX}/share/applications
.for size in 16 32 48 64 128 256
	${INSTALL_DATA} ${WRKDIR}/tdm-${size}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/thedarkmod.png
.endfor

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
