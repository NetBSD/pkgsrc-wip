# $NetBSD$

# The DISTNAME adds '-engine' suffix on purpose to avoid conflict with the
# other distfile, which contains the actual multimedia assets for the game.
DISTNAME=	warsow-engine-2.1.2
PKGNAME=	warsow-2.1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_PROJECT=	warsow
GITHUB_TAG=	${PKGVERSION_NOREV}-pkgsrc
DISTFILES=	${DEFAULT_DISTFILES} warsow-2.1.2.tar.gz
SITES.warsow-2.1.2.tar.gz=	https://warsow.net/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://warsow.net/
COMMENT=	Free fast-paced first-person shooter
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/warsow-2.1.2-pkgsrc/source
WARSOW_DATA_SRC=	${WRKDIR}/warsow-2.1.2/basewsw
USE_TOOLS+=		pax
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/warsow
INSTALLATION_DIRS+=	share/warsow/libs
INSTALLATION_DIRS+=	share/warsow/basewsw

WARSOW_PROGRAMS+=	warsow
WARSOW_PROGRAMS+=	wsw_server
WARSOW_PROGRAMS+=	wswtv_server

WARSOW_INTERNAL_LIBS+=	libangelwrap.so
WARSOW_INTERNAL_LIBS+=	libcin.so
WARSOW_INTERNAL_LIBS+=	libftlib.so
WARSOW_INTERNAL_LIBS+=	libirc.so
WARSOW_INTERNAL_LIBS+=	libref_gl.so
WARSOW_INTERNAL_LIBS+=	libsnd_openal.so
WARSOW_INTERNAL_LIBS+=	libsnd_qf.so
WARSOW_INTERNAL_LIBS+=	libsteamlib.so
WARSOW_INTERNAL_LIBS+=	libui.so

WARSOW_BASEWSW_LIBS+=	libcgame.so
WARSOW_BASEWSW_LIBS+=	libgame.so

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/warsow.template > ${WRKDIR}/warsow

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/warsow ${DESTDIR}${PREFIX}/bin/warsow
	for prog in ${WARSOW_PROGRAMS}; do							\
		${INSTALL_PROGRAM}								\
			${WRKSRC}/build/$${prog} ${DESTDIR}${PREFIX}/share/warsow/$${prog};	\
	done
	for lib in ${WARSOW_INTERNAL_LIBS}; do								\
		${INSTALL_LIB}										\
			${WRKSRC}/build/libs/$${lib} ${DESTDIR}${PREFIX}/share/warsow/libs/$${lib};	\
	done
	cd ${WARSOW_DATA_SRC} && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/warsow/basewsw/
	for lib in ${WARSOW_BASEWSW_LIBS}; do									\
		${INSTALL_LIB}											\
			${WRKSRC}/build/basewsw/$${lib} ${DESTDIR}${PREFIX}/share/warsow/basewsw/$${lib};	\
	done

.include "../../devel/cmake/build.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
