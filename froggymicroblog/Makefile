# $NetBSD: Makefile,v 1.4 2009/08/12 02:32:04 obache Exp $
#

DISTNAME=	frogmicroblog-0.1.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://froggymicroblog.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/froggymicroblog/
COMMENT=	C\# twitter identi.ca client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	FluxRss/fluxrss.pc.in
PKGCONFIG_OVERRIDE+=	Gconf/frogconf.pc.in
PKGCONFIG_OVERRIDE+=	Metier/frogmetier.pc.in
PKGCONFIG_OVERRIDE+=	Twitter/frogtwitter.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../wip/notify-sharp/buildlink3.mk"
.include "../../wip/webkit-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
