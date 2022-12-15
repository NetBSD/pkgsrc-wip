# $NetBSD$

DISTNAME=	biolibc-tools-0.1.4.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	24d8447710c15ad258c3203218aaa32e28ecae6a

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
MAKE_ENV+=	VERSION=${PKGVERSION}
INSTALL_TARGET=	install-strip

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
