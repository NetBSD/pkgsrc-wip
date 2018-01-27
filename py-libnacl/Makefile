# $NetBSD$

DISTNAME=	libnacl-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libnacl/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/saltstack/libnacl
COMMENT=	Python bindings for libsodium based on ctypes
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/libnacl-1.5.2
USE_LANGUAGES=	# none

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
