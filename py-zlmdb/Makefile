# $NetBSD$

DISTNAME=	zlmdb-20.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zlmdb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/crossbario/zlmdb
COMMENT=	Object-relational zero-copy in-memory database layer for LMDB
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-lmdb>=0.94:../../databases/py-lmdb
DEPENDS+=	${PYPKGPREFIX}-cbor2>=5.1.0:../../wip/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-txaio>=20.3.1:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.15.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.3.0:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.3.1:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
