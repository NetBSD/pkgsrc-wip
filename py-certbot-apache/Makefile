# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-apache/}
CATEGORIES=	security

COMMENT=	Apache plugin for Certbot
LICENSE=	apache-2.0

.include "../../wip/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../wip/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot-${PKGVERSION_NOREV}{nb*,}:../../wip/py-certbot

DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_apache/}

PYSETUPSUBDIR=	certbot-apache

SUBST_CLASSES+=         path
SUBST_STAGE.path=       pre-build
SUBST_MESSAGE.path=     Fixing default paths
SUBST_FILES.path+=	certbot-apache/certbot_apache/augeas_lens/httpd.aug
SUBST_FILES.path+=	certbot-apache/certbot_apache/constants.py
SUBST_SED.path+=        -e 's,/etc,${PKG_SYSCONFBASE},g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
