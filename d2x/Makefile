# $NetBSD: Makefile,v 1.6 2004/01/25 02:11:56 grantbeattie Exp $
#

DISTNAME=	d2x-0.2.5
CATEGORIES=	games x11
MASTER_SITES=	http://icculus.org/d2x/src/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://icculus.org/d2x/
COMMENT=	Descent II port

HAS_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES

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

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
