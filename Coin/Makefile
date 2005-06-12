# $NetBSD: Makefile,v 1.7 2005/06/12 23:51:13 kristerw Exp $

DISTNAME=		Coin-2.2.1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Free, portable, Open Inventor API implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-3ds-import --disable-debug

.include "../../graphics/simage/buildlink3.mk"
#.include "../../audio/openal/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
CONFIGURE_ARGS+=        --with-pthreads=yes --enable-threadsafe
.endif

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
