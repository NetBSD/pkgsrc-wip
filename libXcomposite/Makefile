# $NetBSD: Makefile,v 1.2 2003/12/30 20:08:27 cjep Exp $
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

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xcomposite.pc.in

.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../wip/compositeext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
