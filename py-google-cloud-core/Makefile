# $NetBSD$

VERS=		
DISTNAME=	google-cloud-core-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/googleapis/python-cloud-core
COMMENT=	Google Cloud API client core library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-api-core>=1.19.0:../../devel/py-google-api-core

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
