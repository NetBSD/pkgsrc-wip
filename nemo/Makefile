# $NetBSD: Makefile,v 1.15 2010/06/13 22:47:12 thomasklausner Exp $
#

DISTNAME=	nemo-0.2.4
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.iola.dk/nemo/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iola.dk/nemo/
COMMENT=	File manager based on labels and timestamps
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=		user-destdir

# for stetic
DEPENDS+=	monodevelop-[0-9]*:../../devel/monodevelop

USE_PKGLOCALEDIR= yes
USE_LANGUAGES=	# C#
USE_TOOLS+=	gmake msgfmt pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
