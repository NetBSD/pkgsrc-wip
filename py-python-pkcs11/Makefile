# $NetBSD$

DISTNAME=	python-pkcs11-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=pyauth/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyauth/python-pkcs11/
COMMENT=	PKCS#11/Cryptoki support for Python
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.5.1:../../security/py-asn1crypto

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
