# $NetBSD: Makefile,v 1.4 2007/05/29 21:25:41 cosmedbr Exp $

DISTNAME=		wmii+ixp-20070516
PKGNAME=		wmii-20070516
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/snaps/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Window manager improved 2

CONFLICTS+=		wmii-[0-9]*

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE

.include "../../wip/dmenu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
