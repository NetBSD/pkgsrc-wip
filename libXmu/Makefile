# $NetBSD: Makefile,v 1.9 2004/06/13 15:04:40 minskim Exp $
#

DISTNAME=		libXmu-6.2.3
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Miscellaneous Utilities library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xmu.pc.in
PKGCONFIG_OVERRIDE+=	xmuu.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
