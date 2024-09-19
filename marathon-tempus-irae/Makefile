# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:51 asau Exp $

DISTNAME=	marathon-tempus-irae-20060613
CATEGORIES=	games
MASTER_SITES=	http://nardofiles.bungie.org/
DISTFILES+=	Tempus_Irae.zip Tempus_Premium_Landscapes.zip shots_fired.zip
# common extract suffix
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://nardo.bungie.org/
COMMENT=	Game data for Tempus Irae scenario, playable with Aleph One
LICENSE=	cc-by-nc-nd-v2.5-license

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	:../../games/alephone

.include "../../games/alephone/scenario.mk"
INSTALLATION_DIRS=	${SCENARIO_BASE}/TempusIrae ${SCENARIO_BASE}/TempusIrae/Scripts ${SCENARIO_BASE}/TempusIrae/tex ${SCENARIO_BASE}/TempusIrae/Themes
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	# .orig files are kept in order to satisfy even a rigorous
	# interpretation of the "ND" part of the license
	${MV} ${WRKDIR}/Tempus_Irae/tex/landscapes ${WRKDIR}/Tempus_Irae/tex/landscapes.orig
	${MV} ${WRKDIR}/Tempus_Irae/Scripts/TempusLandscapes.mml ${WRKDIR}/Tempus_Irae/Scripts/TempusLandscapes.mml.orig
	${MV} ${WRKDIR}/Tempus_Irae/Scripts/Transparent_Sprites.mml ${WRKDIR}/Tempus_Irae/Scripts/Transparent_Sprites.mml.orig

do-install:
	#install the docs into doc dir and other files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${INSTALL_DATA} ${WRKDIR}/Tempus_Irae/*.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKDIR}/Tempus_Irae/*.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKDIR}/Tempus_Irae/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${RM} ${WRKDIR}/Tempus_Irae/*.html
	${RM} ${WRKDIR}/Tempus_Irae/*.pdf
	${RM} ${WRKDIR}/Tempus_Irae/*.txt
	${CP} -r ${WRKDIR}/Tempus_Irae/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae
	${INSTALL_DATA} ${WRKDIR}/Tempus_Premium_Landscapes/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${RM} ${WRKDIR}/Tempus_Premium_Landscapes/*.txt
	${CP} -r ${WRKDIR}/Tempus_Premium_Landscapes/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${RM} ${WRKDIR}/*.txt
	${CP} -r ${WRKDIR}/Scripts/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae/Scripts
	${CP} -r ${WRKDIR}/tex/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae/tex

.include "../../mk/bsd.pkg.mk"
