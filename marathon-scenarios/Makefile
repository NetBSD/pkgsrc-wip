# $NetBSD: Makefile,v 1.7 2012/10/03 15:09:51 asau Exp $
#

# The version number should be incremented 0.1 when a scenario is moved or
# changed (such that its hash is different), 1.0 if one is added/removed.
# It's rather arbitrary and only for pkgsrc's benefit.
DISTNAME=				marathon-scenarios-1.0
CATEGORIES=				games
# Another series
DISTFILES+=				tgi.zip
SITES.tgi.zip=				http://ryoko.treellama.org/
DISTFILES+=				marathonRubiconX.zip
SITES.marathonRubiconX.zip=		http://files5.bungie.org/marathon/
# Another series
DISTFILES+=				Siege_of_NorKorh_-SDL-v2.zip
SITES.Siege_of_NorKorh_-SDL-v2.zip=	ftp://ftp2.fileball.net/fileball/marathon/aleph1/scenarios/
DISTFILES+=				MarathonEvil.zip
SITES.MarathonEvil.zip=			http://trilogyrelease.bungie.org/files/
# Standalone games
DISTFILES+=				EternalXv103Full.zip
SITES.EternalXv103Full.zip+=		http://eternal.bungie.org/files/_releases/
DISTFILES+=				MarathonRED.zip
SITES.MarathonRED.zip=			http://trilogyrelease.bungie.org/files/
DISTFILES+=				Tempus_Irae.zip
SITES.Tempus_Irae.zip=			http://nardofiles.bungie.org/
# common extract suffix
EXTRACT_SUFX=				.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://traxus.jjaro.net/traxus/Category:Scenarios
COMMENT=	Game data for numerous scenarios playable with the Aleph One engine
LICENSE=	generic-nonlicense

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	:../../games/alephone

RESTRICTED=		Individual scenarios are subject to various licenses, so play it safe.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

SCENARIO_BASE=		share/AlephOne/Scenarios
.for scenario in TheGrayIncident Rubicon \
	SiegeOfNorKorh Evil \
	Eternal Red TempusIrae
INSTALLATION_DIRS+=	${SCENARIO_BASE}/${scenario} ${SCENARIO_BASE}/${scenario}/Physics\ Models ${SCENARIO_BASE}/${scenario}/Scripts ${SCENARIO_BASE}/${scenario}/Themes ${SCENARIO_BASE}/${scenario}/Tracks
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	#clean up irregular author packaging
	${MKDIR} ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/FM\ Net\ Maps.map ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/Marathon\ Files ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/Siege\ of\ Nor\'Korh\ v2.map ${WRKDIR}/SoNK
	find -d ${WRKDIR} -name CVS -exec rm -rf {} \;
	find ${WRKDIR} -name .#* -exec rm -rf {} \;

do-install:
	#install the files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${CP} -r ${WRKDIR}/The\ Gray\ Incident/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TheGrayIncident
	${CP} -r ${WRKDIR}/Rubicon\ X*/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Rubicon
	${CP} -r ${WRKDIR}/SoNK/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/SiegeOfNorKorh
	${CP} -r ${WRKDIR}/Marathon\ EVIL/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Evil
	${CP} -r ${WRKDIR}/Eternal\ X*/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Eternal
	${CP} -r ${WRKDIR}/Marathon\ RED/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Red
	${CP} -r ${WRKDIR}/Tempus_Irae/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TempusIrae

.include "../../mk/bsd.pkg.mk"
