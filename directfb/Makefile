# $NetBSD: Makefile,v 1.3 2003/06/03 02:45:28 xtraeme Exp $
#

DISTNAME=	DirectFB-0.9.18
PKGNAME=	${DISTNAME:S/DirectFB/directfb/}
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Thin library that provides hardware graphics acceleration

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--with-gfxdrivers=all
#CONFIGURE_ARGS+=	--enable-freetype=no

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
