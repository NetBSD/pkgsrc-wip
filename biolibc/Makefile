# $NetBSD$

DISTNAME=	biolibc-0.1.2.11
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	0165ce2e51726ba7d0ec142844648354427d4027

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

INSTALL_TARGET=	install-strip

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
# For $(shell realpath ...).  != doesn't work in Apple's gmake.
USE_TOOLS=	gmake
BUILD_DEPENDS=	realpath>0:../../wip/realpath
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
