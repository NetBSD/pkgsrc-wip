# $NetBSD$

DISTNAME=	hickle-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/a8/4c/ec0afc58c33d482756cd75e7a48f9e9152199b6bcbe73f373f7a89c2305e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/telegraphic/hickle
COMMENT=	Hickle - an HDF5 based version of pickle
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.8.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.0:../../lang/py-six

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
