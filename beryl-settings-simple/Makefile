# $NetBSD: Makefile,v 1.6 2012/11/13 20:09:29 othyro Exp $
#

DISTNAME=	beryl-settings-simple-0.2.1
PKGREVISION=	3
COMMENT=	"Simple" beryl settings (?)

.include "../../wip/beryl/Makefile.inc"

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

USE_TOOLS+=	gettext-tools intltool

PYTHON_PATCH_SCRIPTS+=	src/beryl-settings-simple.in


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../wip/beryl-settings-bindings/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
