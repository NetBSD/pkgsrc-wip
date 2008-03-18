# $NetBSD: Makefile,v 1.2 2008/03/18 00:51:48 tnn2 Exp $
#

DISTNAME=		lat-1.2.3
CATEGORIES=		databases
MASTER_SITES=		http://dev.mmgsecurity.com/downloads/lat/1.2/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://dev.mmgsecurity.com/projects/lat/
COMMENT=		LDAP Administration Tool written in Mono

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config perl gmake msgfmt
USE_LANGUAGES=		# empty -> its csharp
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_DIRS+=		xdg-1.4 \
			gnome2-1.6

PKGCONFIG_OVERRIDE+=	desktop/lat-plugins.pc.in

.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
