# $NetBSD$

PKGNAME=	xxhash-0.6.2
DISTNAME=	xxHash-${PKGVERSION_NOREV}
CATEGORIES=	misc
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Extremely fast non-cryptographic hash algorithm
HOMEPAGE=	https://github.com/Cyan4973/xxHash/
LICENSE=	2-clause-bsd AND gnu-gpl-v2

EXTRACT_USING=	gtar
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME}
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_ENV} ${INSTALL_PROGRAM} ${WRKSRC}/xxhsum ${DESTDIR}${PREFIX}/bin
	${INSTALL_ENV} ${INSTALL_PROGRAM} ${WRKSRC}/xxhsum32 ${DESTDIR}${PREFIX}/bin
	${INSTALL_ENV} ${INSTALL_PROGRAM} ${WRKSRC}/xxhsum_inlinedXXH ${DESTDIR}${PREFIX}/bin
	${INSTALL_ENV} ${INSTALL_MAN} ${WRKSRC}/xxhsum.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
