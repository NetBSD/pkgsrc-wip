# $NetBSD$

DISTNAME=	libxtend-0.2.0.42
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	263f24cac102f704c26574c80ec58f1684309ac8

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

.include "../../mk/bsd.pkg.mk"
