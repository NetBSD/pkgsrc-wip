# $NetBSD$

DISTNAME=	libxtend-0.1.3.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	555b14720eb7a8126c45e1008ddb7a03617d4a13

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libxtendc
COMMENT=	Miscellaneous functions to extend libc
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
PLIST.cs=	yes
.endif

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib MANDIR=${PREFIX}/${PKGMANDIR}
PLIST_VARS=	cs

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include "../../mk/bsd.pkg.mk"
