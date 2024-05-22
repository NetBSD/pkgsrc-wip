# $NetBSD$

DISTNAME=	jsonpatch-1.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-patch
COMMENT=	Apply JSON Patches according to RFC 6902
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_PYTEST=	no

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jsonpointer>=1.9:../../wip/py-jsonpointer

post-install:
	cd ${DESTDIR}${PREFIX} &&					\
		${MV} bin/jsondiff bin/jsondiff-${PYVERSSUFFIX} &&	\
		${MV} bin/jsonpatch bin/jsonpatch-${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
