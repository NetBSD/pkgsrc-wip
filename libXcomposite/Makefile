# $NetBSD: Makefile,v 1.8 2004/08/17 21:26:55 thomasklausner Exp $
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
LIBTOOL_LA_FILES+=	lib/libXcomposite.la
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../wip/libXfixes/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../wip/compositeext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
