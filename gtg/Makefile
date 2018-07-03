# $NetBSD: Makefile,v 1.12 2015/02/04 10:10:50 thomasklausner Exp $

DISTNAME=	gtg-0.1.1
PKGREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	http://launchpad.net/gtg/trunk/0.1.1/+download/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gtg.fritalk.com/
COMMENT=	GTG is a personal organizer for the GNOME
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-configobj>=4.6.0:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2, py-gobject

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
