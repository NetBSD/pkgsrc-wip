# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 18:20:11 marc Exp $
#

DISTNAME=		libpixregion-0.1.0
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/snapshots/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cairographics.org/
COMMENT=		Pixel region Library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libpixregion.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/slim/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
