# $NetBSD$

DISTNAME=	google-cloud-storage-1.36.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-cloud-storage/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/googleapis/python-storage
COMMENT=	Google Cloud Storage API client library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.11.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-cloud-core>=1.4.1:../../wip/py-google-cloud-core
DEPENDS+=	${PYPKGPREFIX}-google-resumable-media>=1.2.0:../../wip/py-google-resumable-media
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.0:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
