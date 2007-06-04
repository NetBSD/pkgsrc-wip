# $NetBSD: Makefile,v 1.4 2007/06/04 17:31:26 cosmedbr Exp $

DISTNAME=		dmenu-3.2
CATEGORIES=		misc
MASTER_SITES=		http://www.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://suckless.org/
COMMENT=		Dynamic menu

NO_CONFIGURE=		yes

BUILD_DEFS+=            PKG_SYSCONFBASE

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
