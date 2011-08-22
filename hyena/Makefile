# $NetBSD: Makefile,v 1.5 2011/08/22 11:44:08 thomasklausner Exp $
#

DISTNAME=	hyena-0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hyena/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/Hyena
COMMENT=	Hyena is a C\# library used to make awesome applications
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.data.sqlite.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.gui.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/hyena.pc.in

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
