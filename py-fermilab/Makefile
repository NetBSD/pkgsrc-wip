# $NetBSD$

DISTNAME=	fermilib-0.1a3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/e0/08/cce26340c8a2f2bca318e3c566f458f893c49cd8542a8e84984c8871f04e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.projectq.ch/
COMMENT=	Analyzing, compiling and emulating quantum algorithm for fermions
LICENSE=	apache-2.0


DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.9.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-test>=0.18.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-projectq>=0.3.1:../../wip/py-projectq

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.11.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
