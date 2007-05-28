# $NetBSD: Makefile,v 1.3 2007/05/28 18:29:42 cosmedbr Exp $

DISTNAME=		dmenu-3.1
CATEGORIES=		misc
MASTER_SITES=		http://www.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://suckless.org/
COMMENT=		Dynamic menu

NO_CONFIGURE=		yes

BUILD_DEFS+=            PKG_SYSCONFBASE

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
