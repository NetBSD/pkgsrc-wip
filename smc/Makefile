# $NetBSD: Makefile,v 1.13 2010/01/18 09:38:33 thomasklausner Exp $
#

DISTNAME=		SMC_0.97
PKGNAME=		smc-0.97
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smclone/}
DISTFILES=		${DISTNAME}_source.zip ${DISTNAME}_game.zip \
			music_2.0_RC_1.zip
EXTRACT_ONLY=		${DISTNAME}_source.zip ${DISTNAME}_game.zip

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://smclone.sourceforge.net/
COMMENT=		Super Mario (World) Clone using pretty 2D graphics

GCC_REQD=		3.2

WRKSRC=			${WRKDIR}/0.97
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake automake autoconf

SMCSHARE=${PREFIX}/share/smc

post-extract:
	# Extracting music files
	${UNZIP_CMD} -u -q ${DISTDIR}/music_2.0_RC_1.zip -d ${WRKSRC}

post-patch:
	@cd ${WRKSRC} && \
	${RM} -f data/Makefile.am && \
	${RM} -f docs/Makefile.am && \
	${SH} autogen.sh && \
	${CHMOD} a+x configure && \
	${CP} ${FILESDIR}/smc ${WRKDIR}/.smc

do-install:
	# Installing game executable, data and default configuration
	${INSTALL_DATA_DIR} ${PREFIX}/lib/smc
	${INSTALL_PROGRAM} ${WRKSRC}/src/smc ${PREFIX}/lib/smc
	${INSTALL_SCRIPT} ${WRKDIR}/.smc ${PREFIX}/bin/smc
	${INSTALL_DATA_DIR} ${SMCSHARE}/levels
	${INSTALL_DATA} ${WRKSRC}/data/levels/* ${SMCSHARE}/levels
	${CP} -rf ${WRKSRC}/data/font ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/music ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/pixmaps ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/sounds ${SMCSHARE}
	${CP} -rf ${WRKSRC}/data/world ${SMCSHARE}
	# Installing documentation, license information and install notes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smc/licenses
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/smc
	${INSTALL_DATA} ${WRKSRC}/docs/licenses/* ${PREFIX}/share/doc/smc/licenses

SUBST_CLASSES+=		libpath sharepath
SUBST_STAGE.libpath=	pre-install
SUBST_FILES.libpath=	${WRKDIR}/.smc
SUBST_SED.libpath=	-e 's|LIBPATH|${PREFIX}/lib/smc|g'
SUBST_MESSAGE.libpath=	Setting smc lib path in execution script
SUBST_STAGE.sharepath=	pre-install
SUBST_FILES.sharepath=	${WRKDIR}/.smc
SUBST_SED.sharepath=	-e 's|SHAREPATH|${SMCSHARE}|g'
SUBST_MESSAGE.sharepath=Setting smc share path in execution script

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
