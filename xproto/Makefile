# $NetBSD: Makefile,v 1.11 2004/05/08 20:13:03 minskim Exp $
#

DISTNAME=		xproto-6.6.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X protocol and ancillary headers

CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PKGCONFIG_OVERRIDE+=	xproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
