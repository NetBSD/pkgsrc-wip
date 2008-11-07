# $NetBSD: Makefile,v 1.1.1.1 2008/11/07 17:37:45 christtrekker Exp $
#

# The version number should be incremented 0.1 when a scenario is moved or
# changed (such that its hash is different), 1.0 if one is added/removed.
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

EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://traxus.jjaro.net/traxus/Category:Scenarios
COMMENT=	Game data for numerous scenarios playable with the Aleph One engine

INSTALLATION_DIRS+=	share/AlephOne/Scenarios

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	#install the files into the Scenarios dir

LICENSE=	various
RESTRICTED=	Individual scenarios are subject to various licenses, so play it safe.
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

#DEPENDS+=	:../../games/alephone

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
