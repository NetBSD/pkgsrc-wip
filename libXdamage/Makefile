# $NetBSD: Makefile,v 1.7 2004/08/17 21:26:56 thomasklausner Exp $
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
LIBTOOL_LA_FILES+=	lib/libXdamage.la

PKGCONFIG_OVERRIDE+=	xdamage.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/damageext/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
