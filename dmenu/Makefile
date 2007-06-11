# $NetBSD: Makefile,v 1.5 2007/06/11 10:50:12 shattered Exp $

DISTNAME=		dmenu-3.2
CATEGORIES=		misc
MASTER_SITES=		http://www.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://www.suckless.org/
COMMENT=		Dynamic menu

NO_CONFIGURE=		yes

BUILD_DEFS+=            PKG_SYSCONFBASE

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
