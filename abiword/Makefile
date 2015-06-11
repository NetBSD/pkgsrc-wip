# $NetBSD: Makefile,v 1.10 2015/06/11 16:26:40 nros Exp $

DISTNAME=	abiword-3.0.1
CATEGORIES=	editors
MASTER_SITES=	http://www.abiword.com/downloads/abiword/${PKGVERSION_NOREV}/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abiword.com/
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

CONFLICTS=      abiword-personal-[0-9]* abiword2-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config
USE_LANGUAGES=	c c++

#MAKE_JOBS_SAFE=no

# All configure_args here
# TODO: an options.mk file
CONFIGURE_ARGS+=	--disable-default-plugins	#do not build any plugins by default
#CONFIGURE_ARGS+=	--enable-plugins	#build all plugins
#CONFIGURE_ARGS+=	 --enable-builtin-plugins      ="foo bar baz" # list of plugins to link statically
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support

# Disabled plugins: gda rsvg
# rsvg is not needed with gtk and we don't have libgnomedb
CONFIGURE_ARGS+=	--enable-plugins=""


PKGCONFIG_OVERRIDE+=	libabiword.pc.in

pre-configure:
	cd ${WRKSRC}; \
	autoreconf --force --install

.include "options.mk"

# normal dependecies
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
