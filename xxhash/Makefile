# $NetBSD$

DISTNAME=	xxHash-${PKGVERSION_NOREV}
PKGNAME=	xxhash-0.6.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/Cyan4973/xxHash/
COMMENT=	Extremely fast non-cryptographic hash algorithm
LICENSE=	2-clause-bsd AND gnu-gpl-v2

EXTRACT_USING=	gtar
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.pkg.mk"
