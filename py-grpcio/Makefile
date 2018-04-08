# $NetBSD$

DISTNAME=	grpcio-1.10.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=   ${MASTER_SITE_PYPI:=g/grpcio/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://grpc.io/
COMMENT=	HTTP/2-based RPC framework
LICENSE=	apache-2.0

DEPENDS+=       ${PYPKGPREFIX}-protobuf>=3.5.0:../../devel/py-protobuf
DEPENDS+=       ${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

USE_LANGUAGES+=	c++ c

SUBST_CLASSES+=         prefix
SUBST_STAGE.prefix=     post-patch
SUBST_MESSAGE.prefix=   Fix include path finding Python.h
SUBST_FILES.prefix=     src/python/grpcio/support.py
SUBST_FILES.prefix=     src/python/grpcio/grpc/_cython/cygrpc.c
SUBST_VARS.prefix=      PREFIX

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=       ${PYPKGPREFIX}-futures>=2.2.0:../../devel/py-futures
DEPENDS+=       ${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
