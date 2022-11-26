# $NetBSD$

VERSION=	2.4.1
GITHUB_PROJECT=	xapp
GITHUB_TAG=	refs/tags/master.mint21
DISTNAME=	master.mint21
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/xapp
COMMENT=	Components which are common to multiple desktop environments
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=		${WRKDIR}/xapp-master.mint21

USE_TOOLS=		bash pkg-config intltool gdbus-codegen
USE_PKGLOCALEDIR=	yes

PYTHON_FOR_BUILD_ONLY=	yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
DEPENDS+=		inxi-[0-9]*:../../wip/inxi
DEPENDS+=		${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

# Adjust meson.build
SUBST_CLASSES+=		meson
SUBST_STAGE.meson=	pre-configure
SUBST_MESSAGE.meson=	Fixing meson build
SUBST_FILES.meson=	pygobject/meson.build
SUBST_SED.meson=	-e 's,python3,python${PYVERSSUFFIX},g'

# Adjust scripts
SUBST_CLASSES+=		scripts
SUBST_STAGE.scripts=	post-extract
SUBST_MESSAGE.scripts=	Fixing scripts
SUBST_FILES.scripts=	scripts/upload-system-info
SUBST_SED.scripts=	-e 's,/usr/bin/pastebin,${PREFIX}/bin/pastebin${PYVERSSUFFIX},g'

REPLACE_BASH+=	scripts/xfce4-set-wallpaper  data/80xapp-gtk3-module.sh

REPLACE_PYTHON+=	scripts/pastebin${PYVERSSUFFIX} scripts/upload-system-info status-applets/mate/mate-xapp-status-applet.py

post-extract:
	${MV} ${WRKSRC}/scripts/pastebin \
		${WRKSRC}/scripts/pastebin${PYVERSSUFFIX}

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
