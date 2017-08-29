# $NetBSD$

DISTNAME=	pycryptodomex-3.4.6
PKGNAME=        ${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=     security python
MASTER_SITES=   ${MASTER_SITE_PYPI:=p/pycryptodomex/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	http://www.pycryptodome.org/
COMMENT=	Cryptographic library for Python
LICENSE=        public-domain AND python-software-foundation

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} ${PYSETUP} test

CFLAGS.SunOS+=  -std=c99 -D_XOPEN_SOURCE=600

CONFLICTS+=     ${PYPKGPREFIX}-cryptodome-[0-9]*

BUILDLINK_API_DEPENDS.gmp+=     gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
WRKSRC=	${WRKDIR}/pycryptodomex-3.4.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
