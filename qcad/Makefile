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

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		find make pax
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	shared.pri src/core/RS.cpp src/core/RSettings.cpp
SUBST_FILES.paths+=	scripts/Help/ShowReadme/ShowReadme.js
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'

# Note: Using pax to install the data files duplicates the lax permissions
# from the zip archive. We use 'umask 133' to prevent this, but we must
# create the directories first otherwise they are not searchable.
# When updating you may need to make the package, update the PLIST and then
# remake the package to bootstrap the directory permissions
#
# XXX Or use the .tar.gz archive available from git but it won't extract properly for me
#
#INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications share/${PKGBASE} \
#			lib/${PKGBASE}/plugins/designer lib/${PKGBASE}/plugins/script
AUTO_MKDIRS=	yes

#
# The QCad build system normally links direct to a release dir but this
# causes a lot of problems with libtool dependencies. We patch it so that
# the libs are linked in the source files and add an install target to
# allow pkgsrc to use DESTDIR
# The Qt script bindings are built in Qt version specific subdirectory
# which we can't patch directly, so we create a fake qtscript.pro file
# and use it to overwrite Makefiles. Makefile.qtscript is ignored
#
do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -r -after DESTDIR=
	cd ${WRKSRC}/src/3rdparty && ${QTDIR}/bin/qmake -r -after DESTDIR= \
	    INSTALLS+=target target.path=${PREFIX}/lib/${PKGBASE}/plugins/script \
	    qtscript.pro -o Makefile.qtscript

do-install:
	cd ${WRKSRC} && make INSTALL_ROOT=${DESTDIR} install
	${INSTALL_DATA} ${WRKSRC}/qcad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/qcad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${FIND} ${WRKSRC}/scripts -name \*.orig -rm
	cd ${WRKSRC} && umask 133 && ${PAX} -rw fonts linetypes patterns \
	    plugins scripts themes ts ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	cd ${WRKSRC} && umask 133 && ${PAX} -rw readme.txt examples libraries \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.7
.include "../../x11/qt4-tools/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.7
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../mk/bsd.pkg.mk"
