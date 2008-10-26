# $NetBSD: Makefile,v 1.2 2008/10/26 10:40:23 tnn2 Exp $
#

DISTNAME=		libpciaccess-0.10.4
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		PCI bus access library from modular Xorg X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

.include "../../mk/bsd.pkg.mk"
