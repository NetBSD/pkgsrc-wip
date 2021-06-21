# $NetBSD: Makefile,v 1.15 2020/05/17 19:34:12 adam Exp $

DISTNAME=	hkdf-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hkdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/casebeer/python-hkdf
COMMENT=	HMAC-based Extract-and-Expand Key Derivation Function (HKDF; RFC 5869)
LICENSE=	2-clause-bsd

#DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1:../../devel/py-cffi
#DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	test:test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
