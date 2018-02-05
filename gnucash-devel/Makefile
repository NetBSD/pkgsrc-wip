# $NetBSD: Makefile,v 1.248 2017/07/03 11:49:37 wiz Exp $

DISTNAME=		gnucash-2.7.4
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

DEPENDS+=		guile22-slib>=3.2.1:../../devel/guile22-slib
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=		dconf-[0-9]*:../../devel/dconf

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool makeinfo msgfmt perl:run pkg-config
# for ninja
#USE_TOOLS+=		intltool makeinfo msgfmt perl:run pkg-config

INFO_FILES=		yes

MAKE_ENV+=		GUILE_AUTO_COMPILE=0
USE_CMAKE=		yes
CMAKE_ARGS+=		-DGMOCK_ROOT=${WRKDIR}/googletest-release-1.8.0/googlemock
CMAKE_ARGS+=		-DGTEST_ROOT=${WRKDIR}/googletest-release-1.8.0/googletest
CMAKE_ARGS+=		-DWITH_AQBANKING=OFF
CMAKE_ARGS+=		-DCMAKE_CXX_FLAGS="-Wno-deprecated-declarations"
#CMAKE_ARGS+=		-GNinja
#BUILD_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build

#do-build:
#	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ninja

REPLACE_PERL+=		common/gnc-test-env.pl
REPLACE_PERL+=		libgnucash/backend/xml/test/grab-types.pl
REPLACE_PERL+=		libgnucash/quotes/gnc-fq-dump
REPLACE_PERL+=		util/elegant-sort.pl

PLIST_SRC=		PLIST

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gnucash

# for CMake build
#pre-build:
#	${MKDIR} -p ${WRKDIR}/.home/.local/share

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
.include "../../lang/guile22/buildlink3.mk"
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
