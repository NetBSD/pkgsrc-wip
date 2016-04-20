# $NetBSD: Makefile,v 1.6 2015/06/07 14:24:48 yrmt Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	libmateweather-${MATE_VERSION}
CATEGORIES=	devel

COMMENT=	Weather information access library

PKGCONFIG_OVERRIDE+=	libmateweather/mateweather.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
