# $NetBSD: Makefile,v 1.1 2013/11/02 13:02:52 makoto Exp $

DISTNAME=	graphite2-1.2.3
CATEGORIES=	graphics
MASTER_SITES=	http://sourceforge.net/projects/silgraphite/files/graphite2/
LICENSE=	gnu-lgpl-v2

EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/silgraphite/
COMMENT=	Cross-platform rendering for complex writing systems

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake

do-configure:
	(cd $(WRKSRC) ;  \
	cmake \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	.)

.include "../../mk/bsd.pkg.mk"
