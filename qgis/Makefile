# $NetBSD: Makefile,v 1.9 2006/05/02 21:03:06 thomasklausner Exp $
#

DISTNAME=		qgis-0.7.4
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qgis/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://qgis.org/
COMMENT=		Open Source Geographic Information System

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-grass

SUBST_CLASSES+=		qtbindir
SUBST_STAGE.qtbindir=	pre-build
SUBST_FILES.qtbindir=	create_qm_files.sh
SUBST_SED.qtbindir+=	-e 's:@QTBINDIR:${QTDIR}/bin:g'
SUBST_MESSAGE.qtbindir=	Fixing QT bin path.

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
