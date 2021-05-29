# $NetBSD$

DISTNAME=	libxtend-0.1.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	1dc76e8d561a0e6f006c3c1a9ca4f9202c2ebfda

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libxtendc
COMMENT=	Miscellaneous functions to extend libc
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
# For $(shell realpath ...).  != doesn't work in Apple's make.
USE_TOOLS=	gmake
BUILD_DEPENDS=	realpath>0:../../wip/realpath
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include "../../mk/bsd.pkg.mk"
