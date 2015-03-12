# $NetBSD: Makefile,v 1.2 2015/03/12 20:32:06 tnn2 Exp $

DISTNAME=	syncthing-gtk-0.6.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_PROJECT=	syncthing-gtk
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syncthing/syncthing-gtk
COMMENT=	GTK3 & python based GUI for Syncthing
LICENSE=	gnu-gpl-v2

DEPENDS+=	syncthing>=0.10.23:../../wip/syncthing

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_VERSIONED_DEPENDENCIES=	dateutil

REPLACE_PYTHON+=		*.py scripts/*.py syncthing_gtk/*.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_MESSAGE.paths=	Fixing hard-coded paths
SUBST_FILES.paths=	scripts/syncthing-gtk
SUBST_FILES.paths+=	syncthing-gtk.desktop
SUBST_FILES.paths+=	syncthing_gtk/app.py
SUBST_FILES.paths+=	syncthing_gtk/uisettingsdialog.py
SUBST_FILES.paths+=	syncthing_gtk/wizard.py
SUBST_SED.paths=	-e 's|/usr/share/syncthing-gtk|${PREFIX}/share/syncthing-gtk|'

.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
# XXX --single-version-externally-managed comes from egg.mk, setup.py does not understand this
_PYSETUPTOOLSINSTALLARGS:=${_PYSETUPTOOLSINSTALLARGS:N--single-version-externally-managed}
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
