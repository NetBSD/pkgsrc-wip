# $NetBSD: Makefile,v 1.1.1.1 2003/04/10 19:20:07 jmmv Exp $
#

DISTNAME=	BillardGL-1.75
PKGNAME=	BillardGL
CATEGORIES=	games
MASTER_SITES=	http://wesley.informatik.uni-freiburg.de/~nopper/BillardGL/download/

MAINTAINER=	wojtek@3miasto.net
HOMEPAGE=	http://www.tobias-nopper.de/BillardGL/
COMMENT=	3D Billard
USE_GMAKE=	yes

pre-configure:
	cd ${WRKSRC}; mv src/* .

.include "../../mk/bsd.pkg.mk"
