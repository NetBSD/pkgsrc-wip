# $NetBSD: Makefile,v 1.3 2014/12/22 23:30:44 thomasklausner Exp $

DISTNAME=	abiword-3.0.0
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/abiword/3.0.0/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abisource.com/downloads/abiword/3.0.0/source/
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

CONFLICTS=      abiword-plugins-[0-9]* abiword-personal-[0-9]* abiword2-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

# All configure_args here
# TODO: an options.mk file
#CONFIGURE_ARGS+=	--disable-default-plugins	#do not build any plugins by default
CONFIGURE_ARGS+=	--enable-plugins=	YES	#build all plugins
#CONFIGURE_ARGS+=	 --enable-builtin-plugins      ="foo bar baz" # list of plugins to link statically
#CONFIGURE_ARGS+=	--enable-debug         # Enable debugging functionality, verbose terminal output
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support

PKGCONFIG_OVERRIDE+=	libabiword.pc.in


.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
