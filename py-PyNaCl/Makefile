# $NetBSD$

DISTNAME=	PyNaCl-1.1.2
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_PYPI:=P/PyNaCl/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/pyca/pynacl
COMMENT=	Python binding to the Networking and Cryptography (NaCl) library
LICENSE=        apache-2.0

INSTALLATION_DIRS=     ${PYSITELIB}

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
