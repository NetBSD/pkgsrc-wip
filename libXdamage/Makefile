# $NetBSD: Makefile,v 1.2 2004/02/17 02:55:51 blef Exp $
#

DISTNAME=		libXdamage-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xdamage extension (Library)

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xdamage.pc.in

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/damageext/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
