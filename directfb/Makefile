# $NetBSD: Makefile,v 1.8 2003/07/24 06:02:20 xtraeme Exp $
#

DISTNAME=	DirectFB-0.9.19
PKGNAME=	${DISTNAME:S/DFB/dfb/}
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Thin library that provides hardware graphics acceleration

ONLY_FOR_PLATFORM=     Linux-*-* NetBSD-*-*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--with-gfxdrivers=all

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.include "../../devel/SDL/buildlink2.mk"
.endif

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
