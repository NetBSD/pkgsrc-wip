# $NetBSD: Makefile,v 1.10 2004/09/30 12:32:05 thomasklausner Exp $
#

DISTNAME=		libXcomposite-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcomposite extension (library)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
