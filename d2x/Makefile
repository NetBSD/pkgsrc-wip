# $NetBSD: Makefile,v 1.1.1.1 2003/11/04 21:19:19 airhead Exp $
#

DISTNAME=	d2x-0.2.5
CATEGORIES=	games x11
MASTER_SITES=	http://icculus.org/d2x/src/

MAINTAINER=	airhead@sourceforge.net
HOMEPAGE=	http://icculus.org/d2x/
COMMENT=	Descent II port

HAS_CONFIGURE=		YES
USE_GMAKE=		YES

#
# Network disabled for now, since only IPX is supported which NetBSD doesn't
# support
#
CONFIGURE_ARGS+=	--disable-network
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sharepath=${PREFIX}/share/games/${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/${PKGBASE}

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
