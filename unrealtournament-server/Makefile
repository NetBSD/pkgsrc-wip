# $NetBSD: Makefile,v 1.5 2007/07/30 15:49:11 jlamwww Exp $
#

DISTNAME=	ut-server-436
PKGNAME=	${DISTNAME:S/ut/unrealtournament/}
WRKSRC=		${WRKDIR}/ut-server
CATEGORIES=	games
MASTER_SITES=	http://public.planetmirror.com/pub/lokigames/installers/ut/

MAINTAINER=	grant@NetBSD.org
COMMENT=	Server for Unreal Tournament first person shooter

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

BUILD_DIRS=		# empty

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/UnrealTournament-server
	cd ${WRKSRC} && ${PAX} -rw -pm . ${PREFIX}/UnrealTournament-server
	cd ${PREFIX}/UnrealTournament-server && \
		${LN} -s -f libSDL-1.1.so.0 libSDL-1.2.so.0

.include "../../mk/bsd.pkg.mk"
