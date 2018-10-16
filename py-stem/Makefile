# $NetBSD$

DISTNAME=	stem-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stem.torproject.org/index.html
COMMENT=	Python controller library for Tor
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

TEST_DEPENDS+=	tor-[0-9]*:../../net/tor
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} run_tests.py --all --log TRACE

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
