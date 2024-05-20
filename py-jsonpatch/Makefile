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

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-jsonpointer>=1.9:../../wip/py-jsonpointer

post-install:
	cd ${DESTDIR}${PREFIX} &&					\
		${MV} bin/jsondiff bin/jsondiff-${PYVERSSUFFIX} &&	\
		${MV} bin/jsonpatch bin/jsonpatch-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
