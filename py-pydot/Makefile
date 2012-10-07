# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	pydot-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pydot.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pydot/
COMMENT=	Python interface to Graphviz Dot
#LICENSE=		mit-license

#DEPENDS+=	${PYPKGPREFIX}-parsing>=1.5.2:../../wip/py-parsing

USE_LANGUAGES=	# none

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
