# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	xapps-1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	xapps
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/xapps
COMMENT=	Components which are common to multiple desktop environments
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

SUBST_CLASSES=		pypath
SUBST_STAGE.pypath=	post-patch
SUBST_FILES.pypath=	pygobject/meson.build files/meson.build
SUBST_VARS.pypath=	PREFIX PYTHONBIN

PY_PATCHPLIST=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libxapp

USE_TOOLS+=	gmake bash pkg-config intltool msgfmt

REPLACE_PYTHON=	schemas/meson_install_schemas.py	\
		files/usr/bin/pastebin			\
		files/usr/bin/upload-system-info

REPLACE_BASH=	files/usr/bin/xfce4-set-wallpaper

pre-install:
	${CHMOD} +x ${WRKSRC}/schemas/meson_install_schemas.py

.include "../../devel/py-meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
