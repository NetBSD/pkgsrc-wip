# $NetBSD: Makefile,v 1.6 2004/05/13 23:10:29 blef Exp $
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

.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/fixesext/buildlink3.mk"
.include "../../wip/compositeext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
