# $NetBSD$

DISTNAME=	archan-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/archan/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Pawamoy/archan
COMMENT=	Analysis of your architecture strength based on DSM data
LICENSE=	isc

USE_LANGUAGES=	# non

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.1:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
