# $NetBSD: Makefile,v 1.18 2012/07/07 11:47:20 mwdavies Exp $
#

DISTNAME=	koffice-2.3.3
PKGREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-2.3.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE4 office suite
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_INTERPRETER_SKIP+=	share/kde/apps/kword/scripts/samples/*

REPLACE_INTERPRETER+=	sys-KROSS
REPLACE.sys-KROSS.old=	.*kross
REPLACE.sys-KROSS.new=	${PREFIX}/bin/kross
REPLACE_FILES.sys-KROSS= \
	kplato/plugins/scripting/scripts/*.py \
        kspread/plugins/scripting/scripts/*.py \
        kword/plugins/scripting/scripts/*.py \
	kword/plugins/scripting/scripts/*.rb

REPLACE_PYTHON+= \
	kword/plugins/scripting/scripts/*.py

# CMake doesn't find it
#.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../databases/mysql51-client/buildlink3.mk"
# CMake doesn't find it
#.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
#.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/ruby/replace.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../print/okular/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
# CMake doesn't find it
#.include "../../mk/pgsql.buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
