# $NetBSD: Makefile,v 1.1.1.1 2007/03/17 22:30:26 cosmedbr Exp $

DISTNAME=		dmenu-2.8
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
