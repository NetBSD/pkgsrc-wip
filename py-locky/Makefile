# $NetBSD$

DISTNAME=	loky-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ac/02/815e43e69592a8a0eabc3d3d99f3e83eb6e401bc248046767f33417d9f08/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/joblib/loky/
COMMENT=	Implementation of concurrent.futures.ProcessPoolExecutor
LICENSE=	2-clause-bsd

#DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=0.2.1:../../wip/py-cloudpickle
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=1.5.1:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
