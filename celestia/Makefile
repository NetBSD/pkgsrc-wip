# $NetBSD: Makefile,v 1.6 2003/05/08 17:30:28 lsed Exp $
#

.include "../../wip/celestia/Makefile.common"

COMMENT=	Free real-time 3D space simulator

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-kde

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
