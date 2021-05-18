# $NetBSD$

DISTNAME=	biolibc-0.1.1.35
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	7a80a9840f9c38f48977ec342e245e396c41fafd

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
