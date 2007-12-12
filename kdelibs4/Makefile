# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 03:17:10 mwdavies Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDELibsDependencies.cmake
CMAKE_MODULE_PATH_OVERRIDE+=	kjsembed/qtonly/CMakeLists.txt

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4/applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/applications.menu

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7 ${PKGMANDIR}/man8

REPLACE_PERL+= \
	kio/proxytype.pl \
	kio/useragent.pl \
	kio/misc/fileshareset \
	kdeui/preparetips

CHECK_PORTABILITY_SKIP+=kate/tests/highlight.sh

.include "../../wip/kde4/kde4.mk"

# Soprano
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../wip/strigi/buildlink3.mk"
# .include "../../audio/libaudiofile/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
# .include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
# .include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
# .include "../../graphics/tiff/buildlink3.mk"

# Avahi ? rather than mDNSResponder
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
# .include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
# .include "../../mk/oss.buildlink3.mk"

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
