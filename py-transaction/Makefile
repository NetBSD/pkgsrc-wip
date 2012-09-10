# $NetBSD: Makefile,v 1.3 2012/09/10 23:43:45 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/transaction-1.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
