# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-nginx/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=certbot/}

COMMENT=	Nginx plugin for Certbot
LICENSE=	apache-2.0

.include "../../wip/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../wip/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot-${PKGVERSION_NOREV}{nb*,}:../../wip/py-certbot

DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_nginx/}

PYSETUPSUBDIR=	certbot-nginx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
