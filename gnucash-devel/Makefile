# $NetBSD: Makefile,v 1.248 2017/07/03 11:49:37 wiz Exp $

DISTNAME=		gnucash-2.7.2
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}
EXTRACT_SUFX=		.tar.bz2
# take copy mirrored on ftp.NetBSD.org for devel/googletest
# for better DISTNAME
# depending on googletest package is not sufficient since not all
# files that are used are installed
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} googletest-1.8.0.tar.gz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

DEPENDS+=		guile-slib>=3.2.1:../../devel/guile-slib
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=		dconf-[0-9]*:../../devel/dconf

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool makeinfo msgfmt perl:run pkg-config
USE_TOOLS+=		autoconf automake autoreconf
GNU_CONFIGURE=		yes
INFO_FILES=		YES

CONFIGURE_ARGS+=	--disable-error-on-warning
CONFIGURE_ARGS+=	--with-xdg-data-dirs=${PREFIX}/share
CONFIGURE_ARGS+=	GTEST_ROOT=${WRKDIR}/googletest-release-1.8.0/googletest
CONFIGURE_ARGS+=	GMOCK_ROOT=${WRKDIR}/googletest-release-1.8.0/googlemock

REPLACE_PERL+=		common/gnc-test-env.pl
REPLACE_PERL+=		libgnucash/backend/xml/test/grab-types.pl
REPLACE_PERL+=		libgnucash/quotes/gnc-fq-dump
REPLACE_PERL+=		util/elegant-sort.pl

PLIST_SRC=		PLIST

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gnucash

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=   boost-headers>=1.64.0nb3
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-keyring+=	gnome-keyring>=0.6
.include "../../security/gnome-keyring/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsecret+=	libsecret>=0.18
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
