# $NetBSD$

DISTNAME=	biolibc-tools-0.1.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
MAKE_ENV+=	VERSION=${PKGVERSION}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
INSTALL_TARGET=	install-strip

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
