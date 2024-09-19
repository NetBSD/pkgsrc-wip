# $NetBSD$

DISTNAME=	hkdf-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hkdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/casebeer/python-hkdf
COMMENT=	HMAC-based Extract-and-Expand Key Derivation Function (HKDF; RFC 5869)
LICENSE=	2-clause-bsd

# This package does not have any tests.
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
