# $NetBSD: Makefile,v 1.3 2004/02/17 02:55:50 blef Exp $
#

DISTNAME=		libXcomposite-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcomposite extension (library)

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xcomposite.pc.in

.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../wip/compositeext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
