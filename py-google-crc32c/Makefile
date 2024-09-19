# $NetBSD$

DISTNAME=	google-crc32c-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     devel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=g/google-crc32c}

MAINTAINER=     kamelderouiche@yahoo.com
HOMEPAGE=       https://github.com/googleapis/python-crc32c
COMMENT=        Python wrapper of the C library Google CRC32C
LICENSE=        apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=   27

DEPENDS+=       ${PYPKGPREFIX}-cffi>=1.14.3:../../devel/py-cffi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
