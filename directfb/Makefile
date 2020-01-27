# $NetBSD: Makefile,v 1.25 2012/09/28 21:24:36 asau Exp $

DISTNAME=	DirectFB-0.9.22
PKGNAME=	directfb-0.9.22
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.directfb.org/
COMMENT=	Thin library that provides hardware graphics acceleration
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	Linux-*-* NetBSD-*-*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	directfb.pc.in lib/direct/direct.pc.in \
			lib/fusion/fusion.pc.in lib/voodoo/voodoo.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gfxdrivers=all

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.include "../../devel/SDL/buildlink3.mk"
.endif

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
