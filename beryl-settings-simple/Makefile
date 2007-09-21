# $NetBSD: Makefile,v 1.2 2007/09/21 13:06:50 thomasklausner Exp $
#

DISTNAME=	beryl-settings-simple-0.2.1
PKGREVISION=	1
COMMENT=	"Simple" beryl settings (?)

.include "../../wip/beryl/Makefile.inc"

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

USE_TOOLS+=	gettext-tools intltool

PKG_DESTDIR_SUPPORT+=	user-destdir

PYTHON_PATCH_SCRIPTS+=	src/beryl-settings-simple.in

.include "../../lang/python/application.mk"

.include "../../wip/beryl-settings-bindings/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
