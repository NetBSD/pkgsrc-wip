# $NetBSD: Makefile,v 1.4 2004/02/02 02:27:45 minskim Exp $
#

DISTNAME=		libXfixes-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Xfixes extension of X RandR

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xfixes.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/fixesext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
