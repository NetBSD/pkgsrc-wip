# $NetBSD: Makefile,v 1.9 2004/09/30 12:32:06 thomasklausner Exp $
#

DISTNAME=		libXdamage-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xdamage extension (Library)

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	xdamage.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/damageext/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
