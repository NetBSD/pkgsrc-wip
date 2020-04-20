# $NetBSD$

DISTNAME=	typedload-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typedload/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ltworf/typedload
COMMENT=	Load and dump data from json-like format into typed data structures
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
