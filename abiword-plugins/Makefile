# $NetBSD: Makefile,v 1.1 2015/06/11 16:13:12 nros Exp $

ABIVERSION=	3.0.1
DISTNAME=	abiword-${ABIVERSION}
PKGNAME=	abiword-plugins-${ABIVERSION}
CATEGORIES=	editors
MASTER_SITES=	http://www.abiword.com/downloads/abiword/${PKGVERSION_NOREV}/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.abiword.com/
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../wip/abiword/distinfo
PATCHDIR=	${.CURDIR}/../../wip/abiword/patches

CONFLICTS=      abiword-plugins-[0-9]* abiword-personal-[0-9]* abiword2-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config
USE_LANGUAGES=	c c++

BUILD_DIRS=	plugins

#DEPENDS+=	abiword-${ABIVERSION}{,nb*}:../../wip/abiword

#MAKE_JOBS_SAFE=no

# All configure_args here
# TODO: an options.mk file
CONFIGURE_ARGS+=	--disable-default-plugins	#do not build any plugins by default
#CONFIGURE_ARGS+=	--enable-plugins	#build all plugins
CONFIGURE_ARGS+=	 --enable-builtin-plugins
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support

# Disabled plugins: gda rsvg
# rsvg is not needed with gtk and we don't have libgnomedb
CONFIGURE_ARGS+=	--enable-plugins="\
	aiksaurus \
	applix \
	babelfish \
	bmp \
	clarisworks \
	collab \
	command \
	docbook \
	eml \
	epub \
	freetranslation \
	garble \
	gdict \
	gimp \
	goffice \
	google \
	grammar \
	hancom \
	hrtext \
	iscii \
	kword \
	latex \
	loadbindings \
	mathview \
	mht \
	mif \
	mswrite \
	opendocument \
	openwriter \
	openxml \
	opml \
	ots \
	paint \
	passepartout \
	pdb \
	pdf \
	presentation \
	psion \
	s5 \
	sdw \
	t602 \
	urldict \
	wikipedia \
	wmf \
	wml \
	wordperfect \
	wpg \
	xslfo"


PKGCONFIG_OVERRIDE+=	libabiword.pc.in

pre-configure:
	cd ${WRKSRC}; \
	autoreconf --force --install

.include "../../wip/abiword/options.mk"

# normal dependecies
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"

#plugin dependecies
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/psiconv/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../misc/goffice0.10/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/aiksaurus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/link-grammar/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../wip/abiword/buildlink3.mk"
.include "../../wip/asio/buildlink3.mk"
.include "../../wip/gtkmathview/buildlink3.mk"
.include "../../wip/libchamplain012/buildlink3.mk"
.include "../../wip/libeps/buildlink3.mk"
.include "../../wip/ots/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
