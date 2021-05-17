# $NetBSD$

DISTNAME=	biolibc-0.1.1.31
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f9161cbc5bcea0279cfa2af91a254a543685e104

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
