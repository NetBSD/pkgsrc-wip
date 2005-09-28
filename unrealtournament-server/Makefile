# $NetBSD: Makefile,v 1.3 2005/09/28 20:50:11 rillig Exp $
#

DISTNAME=	ut-server-436
PKGNAME=	${DISTNAME:S/ut/unrealtournament/}
WRKSRC=		${WRKDIR}/ut-server
CATEGORIES=	games
MASTER_SITES=	http://public.planetmirror.com/pub/lokigames/installers/ut/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://files.sobservers.com/UnrealTournament/UTServerOnly/
COMMENT=	Server for Unreal Tournament first person shooter

NO_BUILD=		yes
SHLIB_HANDLING=		NO

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

DEPENDS.NetBSD+=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/UnrealTournament-server
	cd ${WRKSRC} && ${PAX} -rw -pm . ${PREFIX}/UnrealTournament-server
	cd ${PREFIX}/UnrealTournament-server && \
		${LN} -s -f libSDL-1.1.so.0 libSDL-1.2.so.0

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
