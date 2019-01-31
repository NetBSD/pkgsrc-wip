# $NetBSD$

DISTNAME=	archan-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/4e/7b/44f6cd6c415dcd4177974ca43067d00680d4c69a4abbc6833f309cd5ce79/

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
