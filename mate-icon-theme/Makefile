# $NetBSD: Makefile,v 1.5 2015/04/09 20:38:31 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	mate-icon-theme-${MATE_VERSION}
CATEGORIES=	graphics

COMMENT=	Collection of icons used as the basis for MATE themes

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
