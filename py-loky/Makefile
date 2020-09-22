# $NetBSD$

DISTNAME=	loky-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ac/02/815e43e69592a8a0eabc3d3d99f3e83eb6e401bc248046767f33417d9f08/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/joblib/loky/
COMMENT=	Robust implementation of concurrent.futures.ProcessPoolExecutor
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=0.2.1:../../wip/py-cloudpickle

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
