# $NetBSD: Makefile,v 1.1 2017/01/30 14:16:42 mef Exp $

DISTNAME=	crossguid-0.2.2.52
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=graeme-hill/}
GITHUB_TAG=	ca1bf4b810e2d188d04cb6286f957008ee1b7681
EXTRACT_SUFX=	.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/graeme-hill/crossguid
COMMENT=		C++ GUID library
LICENSE=		mit

USE_LANGUAGES=	c++17 c
USE_CMAKE=	yes

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
