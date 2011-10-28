# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 17:30:05 jihbed Exp $
#

DISTNAME=	HAWK
PKGNAME=	hawk-${VERSION}
CATEGORIES=	physics
MASTER_SITES=	http://omnibus.uni-freiburg.de/~sd565/programs/hawk/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://omnibus.uni-freiburg.de/~sd565/programs/hawk/
COMMENT=	HAWK is a Monte Carlo integrator for pp -> H + 2jets

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	1.1
USE_TOOLS+= gmake
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${GMAKE} -f makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hawk ${DESTDIR}${PREFIX}/bin

.include "../../lang/gcc3-f77/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
