# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:35 thomasklausner Exp $

DISTNAME=	gnome-activity-journal-0.3.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://edge.launchpad.net/gnome-activity-journal/0.3/0.3.3/+download/

MAINTAINER=	pkgsrc.gnome@gmail
HOMEPAGE=	http://live.gnome.org/GnomeActivityJournal
COMMENT=	GUI to browse and search your Zeitgeist activities
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-distutils-extra>=2.15:../../wip/py-distutils-extra
DEPENDS+=	${PYPKGPREFIX}-zeitgeist>=0.3.0:../../wip/py-zeitgeist
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

USE_TOOLS+=	intltool
USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2, py-gobject

GCONF_SCHEMAS+=	extra/gnome-activity-journal.schemas

REPLACE_PYTHON+=	gnome-activity-journal

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1/,man/man1/,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.


.include "../../devel/GConf/schemas.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
