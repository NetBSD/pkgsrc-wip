# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev//:S/letsencrypt/letsencrypt-apache/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=letsencrypt/}

COMMENT=	Apache plugin for Let's Encrypt client
LICENSE=	apache-2.0

.include "../../wip/py-letsencrypt/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../wip/py-acme
DEPENDS+=	${PYPKGPREFIX}-letsencrypt-${PKGVERSION_NOREV}{nb*,}:../../wip/py-letsencrypt

DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/letsencrypt/letsencrypt_apache/}

PYSETUPSUBDIR=	letsencrypt-apache

SUBST_CLASSES+=         path
SUBST_STAGE.path=       pre-build
SUBST_MESSAGE.path=     Fixing default paths
SUBST_FILES.path+=	letsencrypt-apache/letsencrypt_apache/augeas_lens/httpd.aug
SUBST_FILES.path+=	letsencrypt-apache/letsencrypt_apache/constants.py
SUBST_SED.path+=        -e 's,/etc,${PKG_SYSCONFBASE},g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
