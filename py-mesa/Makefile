# $NetBSD$

DISTNAME=	Mesa-0.8.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-reactive/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/projectmesa/mesa
COMMENT=	Agent-based modeling (ABM) in Python 3+
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.3:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.4:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.1:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.4.4:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cookiecutter>=1.7.2:../../devel/py-cookiecutter
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.22.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.1.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.50.2:../../misc/py-tqdm

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
