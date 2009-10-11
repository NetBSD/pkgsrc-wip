# $NetBSD: Makefile,v 1.1.1.1 2009/10/11 13:33:03 jihbed Exp $
#

DISTNAME=	bibliographer-0.1.3
CATEGORIES=	print
MASTER_SITES=	http://launchpad.net/bibliographer/trunk/0.1.3/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://launchpad.net/bibliographer/trunk/0.1.3/+download/
COMMENT=	Bibliographer is a bibtex editor written in Gtk\# and Mono
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
