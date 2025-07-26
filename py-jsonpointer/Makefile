# $NetBSD$

DISTNAME=	jsonpointer-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpointer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-pointer
COMMENT=	Library to resolve JSON Pointers according to RFC 6901
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none
USE_PYTEST=	no

post-install:
	cd ${DESTDIR}${PREFIX} &&					\
		${MV} bin/jsonpointer bin/jsonpointer-${PYVERSSUFFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
