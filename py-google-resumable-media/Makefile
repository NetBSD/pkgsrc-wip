# $NetBSD$

DISTNAME=	google-resumable-media-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-resumable-media/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/googleapis/google-resumable-media-python/
COMMENT=	Utilities for Google Media Downloads and Resumable Uploads
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-google-crc32c>=1.0.0:../../wip/py-google-crc32c

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
