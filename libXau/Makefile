# $NetBSD: Makefile,v 1.6 2004/01/31 22:02:06 minskim Exp $
#

DISTNAME=		libXau-0.1.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Authorization Protocol for X from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xau.pc.in

.include "../../wip/xproto/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
