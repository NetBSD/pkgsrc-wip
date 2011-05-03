# $NetBSD: Makefile,v 1.15 2011/05/03 08:41:22 thomasklausner Exp $
#

DISTNAME=	koffice-2.3.0
PKGREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-2.3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE4 office suite
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		env
SUBST_STAGE.env+=	pre-configure
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/busyinfoclear.py
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/busyinfoexport.py
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/busyinfoimport.py
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/resourcesimport.py
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/sample_busyinfocheck.py
SUBST_FILES.env+=	kplato/plugins/scripting/scripts/sample_project.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/consoledocker.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/csvexport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/csvimport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/htmlexport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/kexidbexport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/kexidbimport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/logger.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/myorca.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/odfpyexport.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/vcardimport.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/xmlviewer.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/xmlviewer.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/functions.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/pyregexp.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/pytime.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/rpyfunctions.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/yfinance.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/yweather.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/doctree.rb
SUBST_FILES.env+=	kword/plugins/scripting/scripts/exportfile.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/importdoxyxml.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/importfile.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/kwreportlab.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/onlinehelp.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/ooimport.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/oouno.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/xmlviewer.py
SUBST_FILES.env+=	kspread/plugins/scripting/scripts/xmlviewer.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_actions.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_allshapes.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_cursor.rb
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_insertshape.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_lists_cursor.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_lists_html.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_progressbar.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_tables.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_text.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_toolactions.py
SUBST_FILES.env+=	kword/plugins/scripting/scripts/sample_variables.py
SUBST_FILES.env+=	tools/okularodpgenerator/okularApplication_odp.desktop
SUBST_SED.env+=		-e "s,/usr/bin/env kross,${PREFIX}/bin/kross,"
SUBST_SED.env+=		-e "s,/usr/bin/env python,${PYTHONBIN},"
SUBST_SED.env+=		-e "s,/usr/bin/env xdg-open,${PREFIX}/bin/xdg-open,"
SUBST_MESSAGE.env+=	Avoid using env.

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../databases/mysql51-client/buildlink3.mk"
# CMake doesn't find it
#.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/kdegraphics4/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
# CMake doesn't find it
#.include "../../mk/pgsql.buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
