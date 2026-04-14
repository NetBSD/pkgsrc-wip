# $NetBSD$

DISTNAME=	slack-libpurple-0.2.20260726
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylex/}
GITHUB_TAG=	1115ec117bcddb38ee0ec649f139d04ab3b53942

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylex/slack-libpurple/
COMMENT=	Slack protocol plugin for libpurple IM clients
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
