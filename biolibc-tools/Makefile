# $NetBSD$

DISTNAME=	biolibc-tools-0.1.1.25
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	632215369982223b21ea0aeb054461dee2a49cc9

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
MAKE_ENV+=	VERSION=${PKGVERSION}
INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
