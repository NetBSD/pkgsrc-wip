# $NetBSD$

DISTNAME=	ptpython-3.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ptpython/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/prompt-toolkit/ptpython
COMMENT=	Python REPL build on top of prompt_toolkit
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=2.0.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.9.0:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.0:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
