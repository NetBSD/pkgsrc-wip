# $NetBSD: Makefile,v 1.13 2005/08/11 10:08:22 absd Exp $
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

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xau.pc.in

.include "../../wip/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
