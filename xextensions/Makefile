# $NetBSD: Makefile,v 1.6 2004/05/09 02:39:48 minskim Exp $
#

DISTNAME=		xextensions-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Various extension headers for xlibs from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PKGCONFIG_OVERRIDE+=	xextensions.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
