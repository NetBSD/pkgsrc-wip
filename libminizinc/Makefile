# $NetBSD$

DISTNAME=	libminizinc-2.9.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=MiniZinc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MiniZinc/libminizinc/
COMMENT=	High-level constraint modelling language
LICENSE=	mpl-2.0

# 11 failed, 3 passed, 1876 skipped

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html>=2:../../devel/py-test-html
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-test-instafail>=0.4:../../devel/py-test-instafail
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-py>=1.11:../../devel/py-py

# XXX
# lots of hacks to get
#git+https://github.com/MiniZinc/minizinc-python.git@develop#egg=minizinc
# installed, but you need to run pre-test manually anyway
USE_TOOLS+=	git
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
pre-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pip install -r requirements.txt

USE_LANGUAGES=	c c++

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"
.include "../../wip/gecode/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
