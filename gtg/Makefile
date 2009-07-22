# $NetBSD: Makefile,v 1.3 2009/07/22 09:53:12 thomasklausner Exp $
#

DISTNAME=	gtg-0.1.1
CATEGORIES=	editors python
MASTER_SITES=	http://launchpad.net/gtg/trunk/0.1.1/+download/

MAINTAINER=	kamelderouiche@iyahoo.com
HOMEPAGE=	http://gtg.fritalk.com/
COMMENT=	GTG is a personal organizer for the GNOME
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-configobj>=4.6.0:../../wip/py-configobj

PKG_DESTDIR_SUPPORT=		user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
