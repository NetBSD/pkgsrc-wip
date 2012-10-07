# $NetBSD: Makefile,v 1.4 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	transaction-1.1.1
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/t/transaction/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.zope.org/Products/ZODB
COMMENT=	Transaction management for Python
LICENSE=		zpl

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface

WRKSRC=		${WRKDIR}/transaction-1.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
