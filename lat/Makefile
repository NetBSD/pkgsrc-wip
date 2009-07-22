# $NetBSD: Makefile,v 1.5 2009/07/22 09:53:13 thomasklausner Exp $
#

DISTNAME=		lat-1.2.3
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://dev.mmgsecurity.com/downloads/lat/1.2/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://dev.mmgsecurity.com/projects/lat/
COMMENT=		LDAP Administration Tool written in Mono

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gmake msgfmt intltool
USE_LANGUAGES=		# empty -> its csharp
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
			gnome2-1.6

PKGCONFIG_OVERRIDE+=	desktop/lat-plugins.pc.in

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
