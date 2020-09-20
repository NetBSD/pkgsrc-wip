# $NetBSD$

DISTNAME=	Serialize-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/7a/63/edc2f11c62301f4b4512367df32217826101d87bb4faa0d0931c11fae8eb/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/hgrecco/serialize
COMMENT=	Multiple serialization formats with support for custom classes
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
# devel/py-serpent: Available for Python2.7
#DEPENDS+=	${PYPKGPREFIX}-serpent>=1.28:../../devel/py-serpent
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-bson>=0.5.10:../../wip/py-bson
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.2:../../wip/py-dill

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
