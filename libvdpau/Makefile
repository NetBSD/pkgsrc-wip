# $NetBSD: Makefile,v 1.1.1.1 2010/01/08 17:34:54 cheusov Exp $
#

DISTNAME=	libvdpau-0.3
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://http.download.nvidia.com/XFree86/vdpau/doxygen/html/index.html
COMMENT=	Video Decode and Presentation API for Unix
#LICENSE=	a la BSD

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	share/doc/libvdpau

PKGCONFIG_OVERRIDE+=	vdpau.pc.in

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} COPYING AUTHORS ${DESTDIR}${PREFIX}/share/doc/libvdpau

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
