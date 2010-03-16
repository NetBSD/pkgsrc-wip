# $NetBSD: Makefile,v 1.3 2010/03/16 19:46:36 jihbed Exp $
#

DISTNAME=	hyena-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hyena/0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/Hyena
COMMENT=	Hyena is a C\# library used to make awesome applications
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	src/Hyena.Gui/hyena.gui.pc.in
PKGCONFIG_OVERRIDE+=	src/Hyena.Data.Sqlite/hyena.data.sqlite.pc.in
PKGCONFIG_OVERRIDE+=	src/Hyena/hyena.pc.in

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
