# $NetBSD: Makefile,v 1.5 2015/04/09 22:07:27 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	caja-extensions-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	Set of extensions for Caja

PKGCONFIG_OVERRIDE+=	sendto/caja-sendto.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../wip/caja/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
