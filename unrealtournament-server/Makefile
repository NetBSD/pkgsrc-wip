# $NetBSD: Makefile,v 1.8 2012/10/07 17:27:16 asau Exp $
#

DISTNAME=	ut-server-436
PKGNAME=	${DISTNAME:S/ut/unrealtournament/}
WRKSRC=		${WRKDIR}/ut-server
CATEGORIES=	games
MASTER_SITES=	http://ut-files.com/Entire_Server_Download/
# original source domain is gone
#MASTER_SITES=	http://public.planetmirror.com/pub/lokigames/installers/ut/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Server for Unreal Tournament first person shooter

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

BUILD_DIRS=		# empty
USE_TOOLS+=		pax

# game developer reply is pending
# LICENSE=	#

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/UnrealTournament-server
	cd ${WRKSRC} && pax -rw -pm . ${DESTDIR}${PREFIX}/UnrealTournament-server
	cd ${DESTDIR}${PREFIX}/UnrealTournament-server && \
		${LN} -s -f libSDL-1.1.so.0 libSDL-1.2.so.0

.include "../../mk/bsd.pkg.mk"
