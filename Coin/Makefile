# $NetBSD: Makefile,v 1.2 2004/02/11 05:19:35 bjan2 Exp $

DISTNAME=		Coin-2.2.1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Free, portable, Open Inventor API implementation

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-3ds-import --disable-debug

USE_X11=		yes

.include "../../wip/simage/buildlink3.mk"
#.include "../../audio/openal/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
CONFIGURE_ARGS+=        --with-pthreads=yes --enable-threadsafe 
.endif

.include "../../mk/bsd.pkg.mk"
