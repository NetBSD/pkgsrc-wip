# $NetBSD: Makefile,v 1.3 2010/12/26 05:01:21 davesainty Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
COMMENT=	Tron clone in 3D with advanced gameplay and multiplayer

MAINTAINER=     pkgsrc-users@NetBSD.org

# Disable server, build client
CONFIGURE_ARGS+=	--disable-dedicated

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
