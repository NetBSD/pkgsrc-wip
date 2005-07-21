# $NetBSD: Makefile,v 1.16 2005/07/21 16:33:58 thomasklausner Exp $
#

DISTNAME=	DirectFB-0.9.19
PKGNAME=	${DISTNAME:S/DFB/dfb/}
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.directfb.org/
COMMENT=	Thin library that provides hardware graphics acceleration

ONLY_FOR_PLATFORM=     Linux-*-* NetBSD-*-*

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-gfxdrivers=all

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.include "../../devel/SDL/buildlink3.mk"
.endif

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
