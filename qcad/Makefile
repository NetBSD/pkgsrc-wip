# $NetBSD: Makefile$
#

DISTNAME=		qcad-3.15.4.1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=qcad/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD system
LICENSE=		gnu-gpl-v3

GITHUB_TAG=		v${PKGVERSION_NOREV}

DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		qt4-tiff-[0-9]*:../../x11/qt4-tiff
DEPENDS+=		qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

USE_TOOLS+=		pax
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	src/core/RS.cpp src/core/RSettings.cpp
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'

# Note: Using pax to install the data files duplicates the lax permissions
# from the zip archive. We use 'umask 133' to prevent this, but we must
# create the directories first otherwise they are not searchable.
# When updating you may need to make the package, update the PLIST and then
# remake the package to bootstrap the directory permissions
#
# XXX Or use the .tar.gz archive available from git but it won't extract properly for me
#
#INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications share/qcad \
#			lib/qcad/plugins/designer lib/qcad/plugins/script
AUTO_MKDIRS=	yes

QCADLIBS=	libqcadcore.la \
		libqcadecmaapi.la \
		libqcadentity.la \
		libqcadgrid.la \
		libqcadgui.la \
		libqcadoperations.la \
		libqcadsnap.la \
		libqcadspatialindex.la \
		libqcadstemmer.la \
		libqcadzip.la \
		libdxflib.a \
		libopennurbs.a \
		libquazip.a \
		libspatialindexnavel.a \
		libstemmer.a \
		libzlib.a

QCADPLUGINS=	plugins/libqcaddxf.la \
		plugins/libqcadexample.la \
		plugins/libtransactionlistener.la \
		plugins/designer/libqcadcustomwidgets.la \
		plugins/script/libqcadqtscript_core.la \
		plugins/script/libqcadqtscript_gui.la \
		plugins/script/libqcadqtscript_network.la \
		plugins/script/libqcadqtscript_opengl.la \
		plugins/script/libqcadqtscript_sql.la \
		plugins/script/libqcadqtscript_svg.la \
		plugins/script/libqcadqtscript_uitools.la \
		plugins/script/libqcadqtscript_webkit.la \
		plugins/script/libqcadqtscript_xml.la \
		plugins/script/libqcadqtscript_xmlpatterns.la

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
	    ${WRKSRC}/release/qcad-bin ${DESTDIR}${PREFIX}/bin/qcad
	${INSTALL_DATA} ${WRKSRC}/qcad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/qcad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for x in ${QCADLIBS}
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/release/${x} ${DESTDIR}${PREFIX}/lib
.endfor
.for x in ${QCADPLUGINS}
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/${x} ${DESTDIR}${PREFIX}/lib/qcad/${x:ts/:H}
.endfor
	cd ${WRKSRC} && umask 133 && ${PAX} -rw fonts libraries linetypes \
	    patterns scripts themes ts ${DESTDIR}${PREFIX}/lib/qcad
	cd ${WRKSRC} && umask 133 && ${PAX} -rw examples ${DESTDIR}${PREFIX}/share/qcad

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.7
.include "../../x11/qt4-tools/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.7
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../mk/bsd.pkg.mk"
