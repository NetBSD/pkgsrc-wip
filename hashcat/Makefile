# $NetBSD$

DISTNAME=	hashcat-3.30
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashcat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashcat/hashcat/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	gmake gsed
BUILD_TARGET=	hashcat

.include "../../mk/bsd.pkg.mk"
