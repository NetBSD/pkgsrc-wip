# $NetBSD: Makefile,v 1.1.1.1 2006/08/21 20:28:19 leuzi Exp $

DISTNAME=	scribus-${PKGVERSION}
PKGNAME=	scribus-devel-${PKGVERSION}
PKGVERSION=	1.3.3.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	http://www.scribus.net/
COMMENT=	Publishing layout with graphical interface

CONFLICTS+=	scribus-[0-9]*

USE_TOOLS+=		gmake perl
USE_LANGUAGES+=		c++

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE+=	libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR:Q} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include

PYTHON_VERSIONS_ACCEPTED=	23 24
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE:Q}

DEPENDS+=	ghostscript-esp>=8.0:../../print/ghostscript-esp

.include "../../print/cups/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
