# $NetBSD$

DISTNAME=	slack-libpurple-0.0.20201029
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylex/}
GITHUB_TAG=	fbbd414ba03821cdfc8f91ee40a722c5bdd4dcc5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylex/slack-libpurple/
COMMENT=	Slack protocol plugin for libpurple IM clients
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES=	c99

.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
