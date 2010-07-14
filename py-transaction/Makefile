# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:21:48 jihbed Exp $
#

DISTNAME=	transaction-1.1.0.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/t/transaction/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.zope.org/Products/ZODB
COMMENT=	Transaction management for Python
LICENSE=		zpl

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/transaction-1.1.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
