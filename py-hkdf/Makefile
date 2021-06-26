# $NetBSD$

DISTNAME=	hkdf-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hkdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/casebeer/python-hkdf
COMMENT=	HMAC-based Extract-and-Expand Key Derivation Function (HKDF; RFC 5869)
LICENSE=	2-clause-bsd

# if devel/py-nose  is not installed, it fails with
#    don't know how to make generate-wrappers
TEST_DEPENDS+=    ${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

# DEPENDS correctly auto-installs, but it gives an unnecessary dependency 
# while not testing
#DEPENDS+=    ${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
