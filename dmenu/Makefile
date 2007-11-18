# $NetBSD: Makefile,v 1.6 2007/11/18 01:23:40 zul_ Exp $

DISTNAME=		dmenu-3.4
CATEGORIES=		misc
MASTER_SITES=		http://www.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://www.suckless.org/
COMMENT=		Dynamic menu

NO_CONFIGURE=		yes

BUILD_DEFS+=            PKG_SYSCONFBASE

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
