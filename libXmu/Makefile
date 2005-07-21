# $NetBSD: Makefile,v 1.14 2005/07/21 16:34:04 thomasklausner Exp $
#

DISTNAME=		libXmu-6.2.3
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Miscellaneous Utilities library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xmu.pc.in
PKGCONFIG_OVERRIDE+=	xmuu.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
