# $NetBSD: Makefile,v 1.1.1.1 2009/12/08 09:54:37 thomasklausner Exp $
#

DISTNAME=		virtualjaguar-1.1.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.xs4all.nl/~shalafi/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdlemu.ngemu.com/
COMMENT=		Jaguar emulator based on SDL

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/vj share/examples/vj
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/virtualjaguar

# Get it from Subversion repository:
SVN_REPOSITORIES=		virtualjaguar
SVN_ROOT.virtualjaguar=		https://shamusworld.gotdns.org/svn/virtualjaguar/trunk/
SVN_MODULE.virtualjaguar=	virtualjaguar
SVN_CERTS=			files/74ccc9063b5068b616abdcf0a1b04cec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vj ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/[A-Za-z]* \
		${DESTDIR}${PREFIX}/share/doc/vj
	${INSTALL_DATA} ${WRKSRC}/vj.cfg ${DESTDIR}${PREFIX}/share/examples/vj

.include "../../devel/SDL/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
