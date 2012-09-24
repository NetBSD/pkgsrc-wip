# $NetBSD: Makefile,v 1.7 2012/09/24 17:14:31 asau Exp $
#

DISTNAME=	bibliographer-0.1.3
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://launchpad.net/bibliographer/trunk/0.1.3/+download/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/bibliographer
COMMENT=	Bibliographer is a bibtex editor written in Gtk\# and Mono
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
