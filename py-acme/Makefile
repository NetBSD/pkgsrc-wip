# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev//:S/letsencrypt/acme/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=letsencrypt/}

COMMENT=	ACME protocol implementation in Python
LICENSE=	apache-2.0

.include "../../wip/py-letsencrypt/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ndg_httpsclient-[0-9]*:../../security/py-ndg_httpsclient
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

EGG_NAME=	${DISTNAME:S/letsencrypt/acme/}

PYSETUPSUBDIR=	acme

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
