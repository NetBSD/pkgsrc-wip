# $NetBSD: Makefile,v 1.8 2004/05/21 23:59:33 poppnk Exp $
#

DISTNAME=	d2x-0.2.5
CATEGORIES=	games x11
MASTER_SITES=	http://icculus.org/d2x/src/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://icculus.org/d2x/
COMMENT=	Descent II port

HAS_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

D2X_DATA=		${PREFIX}/share/games/${PKGBASE}
MAKE_DIRS=		${D2X_DATA}
MESSAGE_SUBST+=		D2X_DATA=${D2X_DATA}

#
# Network disabled for now, since only IPX is supported which NetBSD doesn't
# support
#
CONFIGURE_ARGS+=	--disable-network
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sharepath=${D2X_DATA}

.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
