# $NetBSD: Makefile,v 1.7 2013/01/21 20:59:36 othyro Exp $
#

DISTNAME=	libgxim-0.4.0
CATEGORIES=	x11
MASTER_SITES=	http://libgxim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libgxim/
COMMENT=	GObject-based XIM protocol library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt msgmerge pkg-config perl xgettext
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	share/libgxim

post-install:
.for f in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/libgxim
.endfor

PKGCONFIG_OVERRIDE+=	libgxim.pc.in

.include "../../devel/check/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
