# $NetBSD: Makefile,v 1.4 2004/05/09 02:39:07 minskim Exp $
#

DISTNAME=		libXdamage-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xdamage extension (Library)

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xdamage.pc.in

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/damageext/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
