# $NetBSD$

DISTNAME=	cloudpickle-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/4e/39/40a2862086fdd55eb1881a499a834bfae98ce70f272ed19385f4c74ebe7c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cloudpipe/cloudpickle
COMMENT=	Extended pickling support for Python objects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

WRKSRC=		${WRKDIR}/cloudpickle-0.2.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
