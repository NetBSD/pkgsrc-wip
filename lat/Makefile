# $NetBSD: Makefile,v 1.11 2013/06/17 12:45:12 thomasklausner Exp $
#

DISTNAME=		lat-1.2.3
PKGREVISION=		5
CATEGORIES=		databases
MASTER_SITES=		http://dev.mmgsecurity.com/downloads/lat/1.2/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://dev.mmgsecurity.com/projects/lat/
COMMENT=		LDAP Administration Tool written in Mono

USE_TOOLS+=		pkg-config gmake msgfmt intltool
USE_LANGUAGES=		# empty -> its csharp
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	desktop/lat-plugins.pc.in


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
