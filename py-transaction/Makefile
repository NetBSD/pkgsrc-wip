# $NetBSD: Makefile,v 1.5 2015/07/15 18:20:12 thomasklausner Exp $

DISTNAME=	transaction-1.1.1
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/transaction/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.zope.org/Products/ZODB
COMMENT=	Transaction management for Python
LICENSE=	zpl-2.0

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface

WRKSRC=		${WRKDIR}/transaction-1.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
