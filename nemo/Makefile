# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	nemo-3.6.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	nemo
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/nemo
COMMENT=	File Manager for Cinnamon
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bash pkg-config intltool autoconf automake autoreconf
CONFIGURE_ARGS+=	--disable-selinux

SUBST_CLASSES=		prefix
SUBST_MESSAGE.prefix=	Fix prefix references
SUBST_FILES.prefix=	src/nemo-interesting-folder-bar.c
SUBST_FILES.prefix+=	src/nemo-properties-window.c
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e 's,/usr/share,${PREFIX}/share,g'

DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	gvfs-[0-9]*:../../sysutils/gvfs
BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

REPLACE_PYTHON=	data/merge_action_strings \
		files/usr/share/nemo/actions/myaction.py \
		files/usr/share/nemo/actions/send-by-mail.py

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

pre-install:
	cd ${WRKSRC}/files && mv usr/share . && rmdir usr

#.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/xapps/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
