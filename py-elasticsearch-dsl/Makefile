# $NetBSD$

DISTNAME=	elasticsearch-dsl-7.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elasticsearch-dsl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elasticsearch/elasticsearch-dsl-py
COMMENT=	Python client for Elasticsearch
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-elasticsearch>=7.0.0:../../wip/py-elasticsearch

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
