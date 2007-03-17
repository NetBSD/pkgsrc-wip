# $NetBSD: Makefile,v 1.2 2007/03/17 22:42:20 cosmedbr Exp $

DISTNAME=		wmii-3.6-rc2
PKGNAME=		wmii-3.6rc2
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Window manager improved 2

CONFLICTS=		wmii<3.5

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE

.include "../../wip/libixp/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/dmenu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
