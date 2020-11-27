# $NetBSD: Makefile,v 1.11 2012/12/15 08:27:24 asau Exp $

DISTNAME=	qt-creator-opensource-src-4.13.2
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-opensource-src//}
CATEGORIES=	devel
MASTER_SITES=	http://download.qt.io/official_releases/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
MASTER_SITES+=	http://download.qt.io/archive/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qt.io/
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bash perl

REPLACE_BASH+=	doc/api/examples/aggregation/test.sh
REPLACE_BASH+=	share/qtcreator/scripts/openTerminal.command
REPLACE_BASH+=	src/app/winicons/createicons.sh
REPLACE_BASH+=	src/libs/qmljs/parser/gen-parser.sh
REPLACE_BASH+=	src/shared/qbs/tests/auto/blackbox/testdata/badInterpreter/script-ok
REPLACE_BASH+=	src/shared/qbs/tests/manual/run-qbs-tests.sh
REPLACE_BASH+=	src/shared/qbs/share/qbs/modules/bundle/update-specs.sh
REPLACE_BASH+=	tests/manual/distribution/elflint
REPLACE_BASH+=	scripts/createSourcePackages.sh
REPLACE_BASH+=	scripts/deployqtHelper_mac.sh
REPLACE_BASH+=	scripts/makedmg.sh

REPLACE_PYTHON+=	src/libs/qmljs/parser/changeLicense.py
REPLACE_PYTHON+=	share/qtcreator/templates/wizards/files/python/file.py
REPLACE_PYTHON+=	src/libs/3rdparty/botan/configure.py
REPLACE_PYTHON+=	src/tools/icons/export.py
REPLACE_PYTHON+=	tests/system/tools/findUnusedObjects.py
REPLACE_PYTHON+=	tests/system/tools/objectsToTable.py
REPLACE_PYTHON+=	scripts/checkInstalledFiles.py
REPLACE_PYTHON+=	scripts/dependencyinfo.py
REPLACE_PYTHON+=	scripts/deployqt.py
REPLACE_PYTHON+=	scripts/packageIfw.py
REPLACE_PYTHON+=	scripts/packagePlugins.py
REPLACE_PYTHON+=	scripts/uichanges.py

REPLACE_PERL+=	doc/fixnavi.pl
REPLACE_PERL+=	share/qtcreator/translations/check-ts.pl
REPLACE_PERL+=	src/shared/qbs/doc/fixnavi.pl
REPLACE_PERL+=	tests/auto/qml/qmldesigner/bauhaustests/run_test.pl
REPLACE_PERL+=	scripts/gcc2tasks.pl
REPLACE_PERL+=	scripts/hasCopyright.pl
REPLACE_PERL+=	scripts/krazy2tasks.pl
REPLACE_PERL+=	scripts/msvc2tasks.pl
REPLACE_PERL+=	scripts/mytasks.pl
REPLACE_PERL+=	scripts/purify2tasks.pl
REPLACE_PERL+=	scripts/qdoc2tasks.pl
REPLACE_PERL+=	scripts/test2tasks.pl
REPLACE_PERL+=	scripts/updateCopyright.pl

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}/${PREFIX}
INSTALL_TARGET=		install install_inst_qch_docs

# Has a header called context.h (also in python 3.x) and it includes
# python headers before its own headers.
PYTHON_VERSIONS_ACCEPTED=	27

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib

do-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_ENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake QMAKE_RPATHDIR+=${QTDIR}/lib QMAKE_RPATHDIR+=${X11BASE}/lib -o Makefile

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
