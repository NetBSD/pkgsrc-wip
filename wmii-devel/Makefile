# $NetBSD: Makefile,v 1.6 2007/10/14 12:25:57 hoka_adam Exp $

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

.include "../../wip/dmenu/buildlink3.mk"
.include "../../wip/libixp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
