# $NetBSD$

DISTNAME=	xsdata-26.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xsdata/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/tefra/xsdata/
COMMENT=	Naive XML Bindings for python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=5.0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark
# toposort

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
