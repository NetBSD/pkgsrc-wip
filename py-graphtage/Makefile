# $NetBSD$

DISTNAME=	graphtage-0.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/graphtage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trailofbits/graphtage
COMMENT=	Utility to diff tree-like files such as JSON and XML
LICENSE=	gnu-lgpl-v3 # or later

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
BUILD_DEPENDS+=	${PYPKGPREFIX}-twine>=0:../../net/py-twine
DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-intervaltree>=0:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-json5>=0:../../wip/py-json5
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tqdm>=0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.19.4
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
