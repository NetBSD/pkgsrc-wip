# $NetBSD: Makefile,v 1.2 2003/06/02 16:40:39 xtraeme Exp $
#

DISTNAME=	DirectFB-0.9.17
PKGNAME=	directfb-0.9.17
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Thin library that provides hardware graphics acceleration

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--with-gfxdrivers=all

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
