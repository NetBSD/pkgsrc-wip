# $NetBSD: Makefile,v 1.8 2012/06/12 12:31:45 othyro Exp $
#

DISTNAME=	qt-creator-2.5.0-src
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	http://get.qt.nokia.com/qtcreator/
EXTRACT_SUFX=	.zip

MAINTAINER=	fw@submerge.ch
HOMEPAGE=	http://www.qtsoftware.com/
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=      bin lib/qtcreator lib/qtcreator/plugins/Nokia \
			share/pixmaps share/qtcreator \
			share/qtcreator/translations
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	qt4-tools>=4.6.0:../../x11/qt4-tools \
		qt4-sqlite3>=4.6.0:../../x11/qt4-sqlite3

BUILD_TARGET=	make_default qch_docs
MAKE_ENV+=	PREFIX=${PREFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/qtcreator.sh \
		${DESTDIR}${PREFIX}/bin/
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/qmlprofiler \
		${DESTDIR}${PREFIX}/bin/
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/qtcreator \
		${DESTDIR}${PREFIX}/bin/
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/qtcreator_process_stub \
		${DESTDIR}${PREFIX}/bin/
	${LIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/qtpromaker \
		${DESTDIR}${PREFIX}/bin/
	${LIBTOOL} --mode=install \
		${INSTALL_LIB} ${WRKSRC}/lib/qtcreator/*.la \
		${DESTDIR}${PREFIX}/lib/qtcreator/
	${LIBTOOL} --mode=install \
		${INSTALL_LIB} ${WRKSRC}/lib/qtcreator/plugins/Nokia/*.la \
		${DESTDIR}${PREFIX}/lib/qtcreator/plugins/Nokia/
	${LIBTOOL} --mode=install \
		${INSTALL_DATA} ${WRKSRC}/lib/qtcreator/plugins/Nokia/*.pluginspec \
		${DESTDIR}${PREFIX}/lib/qtcreator/plugins/Nokia/
	${INSTALL_DATA} \
		${WRKSRC}/src/plugins/coreplugin/images/logo/48/qtcreator.png \
		${DESTDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/share/qtcreator/translations/*.qm \
		${DESTDIR}${PREFIX}/share/qtcreator/translations/
	cd ${WRKSRC}/share/qtcreator && ${FIND} designer schemes snippets \
		templates -type d -exec \
                ${INSTALL_DATA_DIR} "${WRKSRC}/share/qtcreator/{}" \
		"${DESTDIR}${PREFIX}/share/qtcreator/{}" ";"
	cd ${WRKSRC}/share/qtcreator && ${FIND} designer schemes snippets \
		templates -type f \! -name "*.orig" -exec \
                ${INSTALL_DATA} "${WRKSRC}/share/qtcreator/{}" \
		"${DESTDIR}${PREFIX}/share/qtcreator/{}" ";"


.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
