# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 18:26:07 marc Exp $
#

DISTNAME=		libic-0.1.5
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/snapshots/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cairographics.org/
COMMENT=		Image compositing library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libic.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/libpixregion/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
