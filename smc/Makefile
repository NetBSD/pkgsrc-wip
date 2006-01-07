# $NetBSD: Makefile,v 1.2 2006/01/07 23:40:01 h2m Exp $
#

PKGNAME=		smc-0.97
DISTNAME=		SMC_0.97
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smclone/}
DISTFILES=		${DISTNAME}_source.zip ${DISTNAME}_game.zip \
			music_2.0_RC_1.zip
EXTRACT_ONLY=		${DISTNAME}_source.zip ${DISTNAME}_game.zip

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://smclone.sf.net/
COMMENT=		Super Mario (World) Clone using pretty 2D graphics

DEPENDS+=		SDL-nas-[0-9]*:../../audio/SDL-nas
GCC_REQD+=		3.2

WRKSRC=			${WRKDIR}/0.97
GNU_CONFIGURE=		YES
USE_TOOLS+=             autoconf automake gmake

SMCSHARE=${PREFIX}/share/smc

post-extract:
	# Extracting music files
	${UNZIP} -u -q ${DISTDIR}/music_2.0_RC_1.zip -d ${WRKSRC}

post-patch:
	@cd ${WRKSRC} && \
	${MV} makefile.am Makefile.am && \
	${MV} src/makefile.am src/Makefile.am && \
	${RM} -f data/makefile.am data/Makefile.am && \
	${RM} -f docs/makefile.am && \
	${SH} autogen.sh && \
	${CHMOD} a+x configure && \
	${CP} ${FILESDIR}/smc-exec.sh ${WRKDIR}

do-install:
	# Installing game executable, data and default configuration
	${INSTALL_PROGRAM} ${WRKSRC}/src/smc ${PREFIX}/bin/smc_bin
	${INSTALL_DATA} -m0555 ${WRKDIR}/smc-exec.sh ${PREFIX}/bin/smc
	${INSTALL_DATA_DIR} -m0777 ${SMCSHARE}/levels
	${INSTALL_DATA} -m0666 ${WRKSRC}/data/levels/* ${SMCSHARE}/levels
	${CP} -rf ${WRKSRC}/data/font ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/music ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/pixmaps ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/sounds ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/world ${SMCSHARE}
	${INSTALL_DATA_DIR} -m0777 ${SMCSHARE}/savegames
	${INSTALL_DATA_DIR} -m0777 ${SMCSHARE}/screenshots
	${INSTALL_DATA} -m0666 ${FILESDIR}/preferences.ini ${SMCSHARE}
	# Installing documentation, license information and install notes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smc/licenses
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/licenses/* ${PREFIX}/share/doc/smc/licenses

post-install:
	${LN} -fs ../../share/smc ${SMCSHARE}/data

SUBST_CLASSES+=		execpath
SUBST_STAGE.execpath=	pre-install
SUBST_FILES.execpath=	${WRKDIR}/smc-exec.sh
SUBST_SED.execpath=	-e 's|EXECPATH|${SMCSHARE}|g'
SUBST_MESSAGE.execpath=	Execution path of the smc binary adjusted

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
