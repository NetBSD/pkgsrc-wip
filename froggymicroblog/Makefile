# $NetBSD: Makefile,v 1.2 2009/06/19 23:47:12 jihbed Exp $
#

DISTNAME=	frogmicroblog-0.1.2.1
CATEGORIES=	www
MASTER_SITES=	http://froggymicroblog.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/froggymicroblog/
COMMENT=	C\# twitter identi.ca client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=		user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	Gconf/gconf.pc.in
PKGCONFIG_OVERRIDE+=	Metier/metier.pc.in
PKGCONFIG_OVERRIDE+=	Twitter/twitter.pc.in

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
