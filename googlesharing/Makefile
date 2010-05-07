# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 14:52:23 hfath Exp $

GOOGLESHAREVERS=	0.9
DISTNAME=		googleshare-${GOOGLESHAREVERS}
PKGNAME=		${PYPKGPREFIX}-googleshare-${GOOGLESHAREVERS}
CATEGORIES=		www python
MASTER_SITES=		http://www.googlesharing.net/server/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://www.googlesharing.net/
COMMENT=		Anonymizing proxy for google searches
LICENSE=		gnu-gpl-v3

PYDISTUTILSPKG=		# yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_VERSIONS_ACCEPTED= 26
REPLACE_PYTHON+=	googleshare.py

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
.if ${MACHINE_ARCH} == "i386"
DEPENDS+=		${PYPKGPREFIX}-psyco-[0-9]*:../../lang/py-psyco
.endif

SUBST_CLASSES+=		ssl-paths
SUBST_STAGE.ssl-paths=	pre-configure
SUBST_FILES.ssl-paths=	googleshare.py
SUBST_SED.ssl-paths+=	-e 's,/etc/ssl/certs,${SSLCERTS},g'
SUBST_SED.ssl-paths+=	-e 's,/etc/ssl/private,${SSLKEYS},g'

USE_LANGUAGES=		# none

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
