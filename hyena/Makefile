# $NetBSD: Makefile,v 1.4 2010/07/21 10:50:23 jihbed Exp $
#

DISTNAME=	hyena-0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hyena/0.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/Hyena
COMMENT=	Hyena is a C\# library used to make awesome applications
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	src/Hyena/hyena.pc.in
PKGCONFIG_OVERRIDE+=	src/Hyena.Data.Sqlite/hyena.data.sqlite.pc.in
PKGCONFIG_OVERRIDE+=	src/Hyena.Gui/hyena.gui.pc.in

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
