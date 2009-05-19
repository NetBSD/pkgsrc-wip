# $NetBSD: Makefile,v 1.5 2009/05/19 09:00:09 thomasklausner Exp $
#

# The version number should be incremented 0.1 when a scenario is moved or
# changed (such that its hash is different), 1.0 if one is added/removed.
# It's rather arbitrary and only for pkgsrc's benefit.
DISTNAME=	marathon-scenarios-1.0
CATEGORIES=	games
# Another series
DISTFILES+=	tgi.zip
SITES.tgi.zip=	http://ryoko.treellama.org/
DISTFILES+=	marathonRubiconX.zip
SITES.marathonRubiconX.zip=	http://files5.bungie.org/marathon/
# Another series
DISTFILES+=	Siege_of_NorKorh_-SDL-v2.zip
SITES.Siege_of_NorKorh_-SDL-v2.zip=	ftp://ftp2.fileball.net/fileball/marathon/aleph1/scenarios/
DISTFILES+=	MarathonEvil.zip
SITES.MarathonEvil.zip=	http://trilogyrelease.bungie.org/files/
# Standalone games
DISTFILES+=	EternalXv103Full.zip
SITES.EternalXv103Full.zip+=	http://eternal.bungie.org/files/_releases/
DISTFILES+=	MarathonRED.zip
SITES.MarathonRED.zip=	http://trilogyrelease.bungie.org/files/
DISTFILES+=	Tempus_Irae.zip
SITES.Tempus_Irae.zip=	http://nardofiles.bungie.org/
# common extract suffix
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://traxus.jjaro.net/traxus/Category:Scenarios
COMMENT=	Game data for numerous scenarios playable with the Aleph One engine
LICENSE=	generic-nonlicense

RESTRICTED=	Individual scenarios are subject to various licenses, so play it safe.
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

SCENARIO_BASE=		share/AlephOne/Scenarios
.for scenario in TheGrayIncident Rubicon \
	SiegeOfNorKorh Evil \
	Eternal Red TempusIrae
INSTALLATION_DIRS+= ${SCENARIO_BASE}/${scenario} ${SCENARIO_BASE}/${scenario}/Physics\ Models ${SCENARIO_BASE}/${scenario}/Scripts ${SCENARIO_BASE}/${scenario}/Themes ${SCENARIO_BASE}/${scenario}/Tracks
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	#clean up irregular author packaging
	${MV} ${WRKDIR}/the\ gray\ incident/scripts ${WRKDIR}/the\ gray\ incident/Scripts
	${MV} ${WRKDIR}/the\ gray\ incident/themes ${WRKDIR}/the\ gray\ incident/Themes
	${MKDIR} ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/fm\ net\ maps.map ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/marathon\ files ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/siege\ of\ nor\'korh\ v2.map ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/tempus_irae/scripts ${WRKDIR}/tempus_irae/Scripts
	${MV} ${WRKDIR}/tempus_irae/themes ${WRKDIR}/tempus_irae/Themes
	find ${WRKDIR} -name CVS -exec rm -rf {} \;

do-install:
	#install the files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${CP} -r ${WRKDIR}/the\ gray\ incident/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TheGrayIncident
	${CP} -r ${WRKDIR}/Rubicon\ X*/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Rubicon
	${CP} -r ${WRKDIR}/SoNK/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/SiegeOfNorKorh
	${CP} -r ${WRKDIR}/Marathon\ EVIL/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Evil
	${CP} -r ${WRKDIR}/Eternal\ X*/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Eternal
	${CP} -r ${WRKDIR}/Marathon\ RED/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Red
	${CP} -r ${WRKDIR}/tempus_irae/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	:../../games/alephone

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
