# $NetBSD: Makefile,v 1.1.1.1 2010/12/07 21:23:29 pallegra Exp $
#

DISTNAME=	i3bar-0.5
CATEGORIES=	x11 wm
MASTER_SITES=	http://git.merovius.de/i3bar/snapshot/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://git.merovius.de/i3bar/
COMMENT=	xcb-based status- and ws-bar for i3
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

MAKE_ENV+=	DEBUG=0
MAKE_ENV+=	I3BAR_VERSION=${DISTAME:C/i3bar-//}

BUILDLINK_DEPMETHOD.i3?=	build
.include "../../wip/i3-devel/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../wip/yajl/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
