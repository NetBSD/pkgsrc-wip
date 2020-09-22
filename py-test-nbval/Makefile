# $NetBSD$

DISTNAME=	nbval-0.9.6
PKGNAME=	${PYPKGPREFIX}-test-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/7a/5c/ae5ea6f6bbaefcb4de94072bd31566682fe927f33ab8bfeb8f0179aa346a/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/computationalmodelling/nbval
COMMENT=	Py.test plugin to validate Jupyter notebooks
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.7:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.0.7:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.3.4:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
