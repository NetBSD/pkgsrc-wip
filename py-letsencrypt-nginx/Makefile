# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev//:S/letsencrypt/letsencrypt-nginx/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=letsencrypt/}

COMMENT=	Nginx plugin for Let's Encrypt client
LICENSE=	apache-2.0

.include "../../wip/py-letsencrypt/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../wip/py-acme
DEPENDS+=	${PYPKGPREFIX}-letsencrypt-${PKGVERSION_NOREV}{nb*,}:../../wip/py-letsencrypt

DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/letsencrypt/letsencrypt_nginx/}

PYSETUPSUBDIR=	letsencrypt-nginx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
