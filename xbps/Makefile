# $NetBSD$

DISTNAME=	xbps-0.51
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=voidlinux/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/voidlinux/xbps/
COMMENT=	The X Binary Package System
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
