# $NetBSD$

PKGNAME=	purple-facebook-0.9.4
CATEGORIES=	chat
DISTNAME=	purple-facebook-0.9.4-c9b74a765767
MASTER_SITES=   ${MASTER_SITE_GITHUB:=jgeboski/}
GITHUB_PROJECT= purple-facebook
GITHUB_RELEASE=	v0.9.4-c9b74a765767

MAINTAINER=	izaac@setec.org
HOMEPAGE=	https://github.com/dequis/purple-facebook
COMMENT=	Facebook protocol plugin for libpurple
LICENSE=	gplv2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
