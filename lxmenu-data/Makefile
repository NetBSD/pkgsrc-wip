# $NetBSD: Makefile,v 1.6 2015/05/30 01:49:33 krytarowski Exp $
#

.include "../../wip/liblxqt/Makefile.common"

# TODO: handle etc files? is etc.xdg okay?
# Default menu file should be put into /etc/xdg/menus according to the spec.
# If you put it into /usr/etc/xdg/menus, nothing will work.
# So, please make sure that lxde-applications.menu is installed in /etc/xdg/menus.


DISTNAME=	lxmenu-data-0.1.4
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LXDE/LXQt menu data

GNU_CONFIGURE=	yes
#USE_LANGUAGES=	# none
USE_TOOLS+=	gmake intltool

.include "../../mk/bsd.pkg.mk"
