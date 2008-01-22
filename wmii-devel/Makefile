# $NetBSD: Makefile,v 1.7 2008/01/22 11:34:56 tnn2 Exp $

DISTNAME=		wmii-20071003
PKGNAME=		${DISTNAME}
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/snaps/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Window manager improved 2

CONFLICTS+=		wmii-[0-9]*

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE

# It's broken on NetBSD 4.99.31
#
MAKE_JOBS_SAFE=no

.include "../../x11/dmenu/buildlink3.mk"
.include "../../devel/libixp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
