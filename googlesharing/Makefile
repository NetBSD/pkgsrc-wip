# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:43 thomasklausner Exp $

GOOGLESHAREVERS=	0.9
DISTNAME=		googleshare-${GOOGLESHAREVERS}
PKGNAME=		${PYPKGPREFIX}-googleshare-${GOOGLESHAREVERS}
CATEGORIES=		www python
MASTER_SITES=		http://www.googlesharing.net/server/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://www.googlesharing.net/
COMMENT=		Anonymizing proxy for google searches
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PYDISTUTILSPKG=		# yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
REPLACE_PYTHON+=	googleshare.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

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
