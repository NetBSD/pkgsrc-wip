# $NetBSD$

DISTNAME=	biolibc-tools-0.1.0.65
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	d82c3590ac19cb8e306f450af7b5ee9900953512

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
.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
