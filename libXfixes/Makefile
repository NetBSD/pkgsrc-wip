# $NetBSD: Makefile,v 1.3 2004/02/02 02:23:56 minskim Exp $
#

DISTNAME=		libXfixes-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Xfixes extension of X RandR

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xfixes.pc.in

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
