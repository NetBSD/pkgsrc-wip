# $NetBSD: Makefile,v 1.2 2012/10/07 17:41:42 asau Exp $
#

DISTNAME=		virtualjaguar-1.1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.xs4all.nl/~shalafi/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdlemu.ngemu.com/
COMMENT=		Jaguar emulator based on SDL

INSTALLATION_DIRS=	bin share/doc/vj share/examples/vj
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/virtualjaguar

GIT_REPOSITORIES=		virtualjaguar
GIT_REPO.virtualjaguar=		http://shamusworld.gotdns.org/git/virtualjaguar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vj ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/[A-Za-z]* \
		${DESTDIR}${PREFIX}/share/doc/vj
	${INSTALL_DATA} ${WRKSRC}/vj.cfg ${DESTDIR}${PREFIX}/share/examples/vj

.include "../../devel/SDL/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
