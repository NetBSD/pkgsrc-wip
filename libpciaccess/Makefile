# $NetBSD: Makefile,v 1.1.1.1 2008/10/06 20:09:55 tnn2 Exp $
#

DISTNAME=		libpciaccess-0.10.3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		PCI bus access library from modular Xorg X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config automake autoconf

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -if

.include "../../mk/bsd.pkg.mk"
