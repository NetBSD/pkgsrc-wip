# $NetBSD$

DISTNAME=	libbgpdump-1.6.2
PKGNAME=	${DISTNAME:S/libbgpdump/bgpdump/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=RIPE-NCC/}
GITHUB_PROJECT=	bgpdump
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tgz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/RIPE-NCC/bgpdump
COMMENT=	BGP dump utility and library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
