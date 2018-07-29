# $NetBSD$

DISTNAME=	pycryptodomex-3.6.4
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycryptodomex/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	http://www.pycryptodome.org/
COMMENT=	Cryptographic library for Python
LICENSE=	public-domain AND python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-cryptodome-[0-9]*

CHECK_PORTABILITY_SKIP+=	appveyor/get_wheels.sh

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} ${PYSETUP} test

BUILDLINK_API_DEPENDS.gmp+=     gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
