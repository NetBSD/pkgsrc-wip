# $NetBSD$

DISTNAME=	biolibc-0.1.2.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	7824a308c1d0e51ff6275f8281df4ee5f2aa7a81

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
