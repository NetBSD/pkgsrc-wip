# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=	libgxim-0.3.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://libgxim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libgxim/
COMMENT=	GObject-based XIM protocol library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config  perl intltool
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	share/libgxim

post-install:
.for f in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f}  ${PREFIX}/share/libgxim
.endfor

PKGCONFIG_OVERRIDE+=	libgxim.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
