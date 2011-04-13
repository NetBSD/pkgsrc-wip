# $NetBSD: Makefile,v 1.4 2011/04/13 13:58:47 obache Exp $
#

DISTNAME=	oxim-1.4.4
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/others/OXIM/Source/tarball/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://opendesktop.org.tw/demopage/oxim/
COMMENT=	Open X Input Method server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	oxim.pc.in

PKG_SYSCONFSUBDIR=	oxim

EXAMPLES_DIR=		share/examples/oxim

CONFIGURE_ARGS+=	--with-conf-dir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	OXIM_DEFAULT_RCDIR=${PREFIX}/${EXAMPLES_DIR}

CONF_FILES+=	${EXAMPLES_DIR}/locale.list ${PKG_SYSCONFDIR}/locale.list
CONF_FILES+=	${EXAMPLES_DIR}/oxim.conf ${PKG_SYSCONFDIR}/oxim.conf

SUBST_CLASSES+=	gtk-localedir
SUBST_STAGE.gtk-localedir=	post-configure
SUBST_FILES.gtk-localedir=	src/gtk-immodule/gtkintl.h
SUBST_FILES.gtk-localedir+=	src/lib/oxim_set_locale.c
SUBST_VARS.gtk-localedir=	PREFIX PKGLOCALEDIR

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
