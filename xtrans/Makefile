# $NetBSD: Makefile,v 1.6 2004/01/31 18:41:01 minskim Exp $
#

DISTNAME=		libXtrans-0.1
PKGNAME=		xtrans-0.1
CATEGORIES=		x11 net
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
