# $NetBSD$

PKGNAME=		dma-0.10
DISTNAME=		dma-${GITHUB_TAG}
CATEGORIES=		mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=corecode/}
GITHUB_PROJECT=	dma
GITHUB_TAG=		v0.10

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/corecode/dma
COMMENT=	The DragonFly Mail Agent
LICENSE=	modified-bsd

NO_CONFIGURE=	yes
USE_LANGUAGES=	c

CFLAGS+=	-DHAVE_GETPROGNAME
CFLAGS+=	-DHAVE_STRLCPY
CFLAGS+=	-DLIBEXEC_PATH=${PREFIX}/libexec

MAKE_FLAGS=		"LIBEXEC=${PREFIX}/libexec"
MAKE_FLAGS+=	"MAN=${PREFIX}/${PKGMANDIR}"

.include "../../mk/bsd.pkg.mk"
