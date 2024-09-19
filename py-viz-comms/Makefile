# $NetBSD$

DISTNAME=	pyviz_comms-0.7.6
PKGNAME=	${PYPKGPREFIX}-viz-comms-0.7.6
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyviz_comms/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyviz.org
COMMENT=	Bidirectional communication for the PyViz ecosystem
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-param>=1.10.0:../../wip/py-param
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.4:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
