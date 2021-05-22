# $NetBSD$

DISTNAME=	biolibc-0.1.2.6
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	bb8ab533e9a78a07a73b064a1a90c119d319988e

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

INSTALL_TARGET=	install-strip

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
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
