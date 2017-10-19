# $NetBSD$

DISTNAME=	vanitygen-0.21
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=samr7/}

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/samr7/vanitygen/
COMMENT=	Vanity address generator
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	gmake

BUILD_TARGET=	most # all: requires OpenCL

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
