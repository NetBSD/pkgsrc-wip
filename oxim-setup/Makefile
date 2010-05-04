# $NetBSD: Makefile,v 1.3 2010/05/04 13:14:19 obache Exp $
#

DISTNAME=	oxim-setup-1.4.4
CATEGORIES=	inputmethod chinese
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/OXIM/Source/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://opendesktop.org.tw/demopage/oxim/
COMMENT=	Open X Input Method setup tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	oxim

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-setup-php
CONFIGURE_ARGS+=	--disable-setup-gambas
CONFIGURE_ARGS+=	--disable-setup-pygtk
INSTALL_MAKE_FLAGS+=	OXIM_DEFAULT_RCDIR=${PREFIX}/${EXAMPLES_DIR}

REPLACE_SH+=		src/utils/oxim-setup.in

.include "options.mk"

SUBST_CLASSES+=		hcpath
SUBST_STAGE.hcpath=	post-configure
SUBST_FILES.hcpath=	src/oxim-setup-gtk-1.1.7/src/oxim_setting_and_config.c
SUBST_FILES.hcpath+=	src/oxim-setup-gtk-1.1.7/src/utils.c
SUBST_FILES.hcpath+=	src/oxim-setup-qt3/main.cpp
SUBST_VARS.hcpath=	PREFIX PKGLOCALEDIR PKG_SYSCONFDIR

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15
.include "../../www/curl/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
BUILDLINK_API_DEPENDS.oxim+=	oxim>=1.4.4
.include "../../wip/oxim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
