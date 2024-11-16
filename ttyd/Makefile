# $NetBSD$

DISTNAME=	ttyd-1.7.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsl0922/}
GITHUB_PROJECT=	ttyd

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/tsl0922/ttyd/
COMMENT=	Simple command-line tool for sharing terminal over the web
LICENSE=	mit

.include "../../devel/libuv/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/libwebsockets/buildlink3.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
