# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 16:14:10 jihbed Exp $
#

DISTNAME=	libgxim-0.3.2
CATEGORIES=	x11
MASTER_SITES=	http://libgxim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/libgxim/
COMMENT=	GObject-based XIM protocol library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool

INSTALLATION_DIRS=	share/libgxim

PKGCONFIG_OVERRIDE+=	libgxim.pc.in

post-install:
.for f in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f}  ${PREFIX}/share/libgxim
.endfor

BUILDLINK_API_DEPENDS.glib2+=	glib2>=0.3.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
