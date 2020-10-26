# $NetBSD$

DISTNAME=	google-cloud-bigquery-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-cloud-bigquery/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/googleapis/python-bigquery
COMMENT=	Google BigQuery API client library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-proto-plus>=1.11.0:../../wip/py-proto-plus
DEPENDS+=	${PYPKGPREFIX}-google-api-core>=1.22.4:../../devel/py-google-api-core
DEPENDS+=	${PYPKGPREFIX}-google-cloud-core>=1.4.3:../../wip/py-google-cloud-core
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.13.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-google-resumable-media>=0.6.0:../../wip/py-google-resumable-media

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
