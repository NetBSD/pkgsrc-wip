# $NetBSD$

DISTNAME=	Mastodon.py-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www chat
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mastodon.py/}

HOMEPAGE=	https://github.com/halcy/Mastodon.py
COMMENT=	Python wrapper for the Mastodon API
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
