# $NetBSD: Makefile,v 1.2 2012/01/30 08:34:45 noud4 Exp $
#

DISTNAME=	transaction-1.1.1.tar
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

WRKSRC=		${WRKDIR}/transaction-1.1.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
