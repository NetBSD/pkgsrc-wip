# $NetBSD: Makefile,v 1.2 2007/04/29 13:59:39 cosmedbr Exp $

DISTNAME=		dmenu-3.0
CATEGORIES=		misc
MASTER_SITES=		http://www.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://suckless.org/
COMMENT=		Dynamic menu

NO_CONFIGURE=		yes

BUILD_DEFS+=            PKG_SYSCONFBASE

#.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
