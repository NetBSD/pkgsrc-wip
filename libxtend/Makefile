# $NetBSD$

DISTNAME=	libxtend-0.1.9.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	8b64249981c90868db8457c90195f3332d0e097b

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libxtendc
COMMENT=	Miscellaneous functions to extend libc
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include "../../mk/bsd.pkg.mk"
