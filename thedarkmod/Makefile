# $NetBSD$

PKGNAME=	thedarkmod-2.07
DISTNAME=	thedarkmod.${PKGVERSION_NOREV}.src
CATEGORIES=	games
MASTER_SITES=	http://www.thedarkmod.com/sources/
EXTRACT_SUFX=	.7z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thedarkmod.com/main/
COMMENT=	First-person stealth video game inspired by the Thief series
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c c++

GCC_REQD+=	8.0
PYTHON_VERSIONS_ACCEPTED=	27

CXXFLAGS+=	-Wfatal-errors

.include "../../mk/bsd.prefs.mk"

CXXFLAGS+=	-DUSE_FILE32API

SCONS_ARGS+=	${_MAKE_JOBS}

.if ${MACHINE_ARCH} == "x86_64"
SCONS_ARGS+=	TARGET_ARCH="x64"
.elif ${MACHINE_ARCH} == "i386"
SCONS_ARGS+=	TARGET_ARCH="x86"
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q} VERBOSE=1 BUILD="release"

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q} \
	--prefix=${DESTDIR}${PREFIX} install

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
