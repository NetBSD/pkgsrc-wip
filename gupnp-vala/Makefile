# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:07 thomasklausner Exp $
#

DISTNAME=	gupnp-vala-0.5.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://gupnp.org/sources/bindings/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gupnp.org/
COMMENT=	Gupnp-vala offers Vala bindings to GUPnP framework
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gupnp-vala-1.0.pc.in

BUILDLINK_API_DEPENDS.vala+=	vala>=0.5.7nb1
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.gupnp+=	gupnp>=0.12.6
.include "../../net/gupnp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gupnp-av+=	gupnp-av>=0.3.1
.include "../../net/gupnp-av/buildlink3.mk"
BUILDLINK_API_DEPENDS.gssdp+=	gssdp>=0.6.4
.include "../../net/gssdp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gupnp-ui+=	gupnp-ui>=0.1.1
.include "../../wip/gupnp-ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
