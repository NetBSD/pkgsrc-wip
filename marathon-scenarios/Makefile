# $NetBSD: Makefile,v 1.2 2008/12/29 16:06:05 christtrekker Exp $
#

# The version number should be incremented 0.1 when a scenario is moved or
# changed (such that its hash is different), 1.0 if one is added/removed.
# It's rather arbitrary and only for pkgsrc's benefit.
DISTNAME=	marathon-scenarios-1.0
CATEGORIES=	games

# The original Bungie trilogy series
DISTFILES=	M1A1.zip
SITES.M1A1.zip=	http://trilogyrelease.bungie.org/files/
DISTFILES+=	Marathon2.zip
SITES.Marathon2.zip=	http://trilogyrelease.bungie.org/files/
DISTFILES+=	MarathonInfinity.zip
SITES.MarathonInfinity.zip=	http://trilogyrelease.bungie.org/files/

# Another series
DISTFILES+=	tgi.zip
SITES.tgi.zip=	http://ryoko.treellama.org/
#Organization of Rubicon is messy...deal with it later.
#DISTFILES+=	marathonRubiconX.zip
#SITES.marathonRubiconX.zip=	http://files5.bungie.org/marathon/

# Another series
DISTFILES+=	Siege_of_NorKorh_-SDL-v2.zip
SITES.Siege_of_NorKorh_-SDL-v2.zip=	ftp://ftp2.fileball.net/fileball/marathon/aleph1/scenarios/
DISTFILES+=	MarathonEvil.zip
SITES.MarathonEvil.zip=	http://trilogyrelease.bungie.org/files/

# Standalone games
#DISTFILES+=	EternalXv103Full.zip
#SITES.EternalXv103Full.zip+=	http://eternal.bungie.org/files/_releases/
#DISTFILES+=	MarathonRED.zip
#SITES.MarathonRED.zip=	http://trilogyrelease.bungie.org/files/
#DISTFILES+=	Tempus_Irae.zip
#SITES.Tempus_Irae.zip=	http://nardofiles.bungie.org/

EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://traxus.jjaro.net/traxus/Category:Scenarios
COMMENT=	Game data for numerous scenarios playable with the Aleph One engine

SCENARIO_BASE=		share/AlephOne/Scenarios
.for scenario in 1 2 Infinity \
	TheGrayIncident Rubicon \
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
	#Rubicon here...
	${MKDIR} ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/fm\ net\ maps.map ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/marathon\ files ${WRKDIR}/SoNK
	${MV} ${WRKDIR}/siege\ of\ nor\'korh\ v2.map ${WRKDIR}/SoNK

do-install:
	#install the files into the Scenarios dir
	#there is no ${INSTALL_...} command with recursive abilities...
	${CP} -r ${WRKDIR}/M1A1/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/1
	${CP} -r ${WRKDIR}/Marathon\ 2/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/2
	${CP} -r ${WRKDIR}/Marathon\ Infinity/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Infinity
	${CP} -r ${WRKDIR}/the\ gray\ incident/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/TheGrayIncident
	#Rubicon here....
	${CP} -r ${WRKDIR}/SoNK/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/SiegeOfNorKorh
	${CP} -r ${WRKDIR}/Marathon\ EVIL/* ${DESTDIR}${PREFIX}/${SCENARIO_BASE}/Evil

LICENSE=	generic-nonlicense
RESTRICTED=	Individual scenarios are subject to various licenses, so play it safe.
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# There is no true dependency on Aleph One.  These scenarios cannot be
# played without it, though.
#DEPENDS+=	:../../games/alephone

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
