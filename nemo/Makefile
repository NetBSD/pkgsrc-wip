# $NetBSD: Makefile,v 1.6 2008/04/27 09:21:35 thomasklausner Exp $
#

DISTNAME=	nemo-0.2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.iola.dk/nemo/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iola.dk/nemo/
COMMENT=	File manager based on labels and timestamps

# for stetic
DEPENDS+=	monodevelop-[0-9]*:../../devel/monodevelop

USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# C#
USE_TOOLS+=	gmake msgfmt pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
