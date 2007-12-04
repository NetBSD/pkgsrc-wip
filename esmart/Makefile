# $NetBSD: Makefile,v 1.1.1.1 2007/12/04 22:08:35 yazzy Exp $
#

DISTNAME=	esmart-0.9.0.011
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.yazzy.org/pkgsrc/e17/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	A collection of evas smart objects.

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	pkg-config
DEPENDS+=	ecore>=0.9.9.041:../../wip/ecore
DEPENDS+=	epsilon>=0.3.0:../../wip/epsilon
DEPENDS+=	jpeg>=6:../../graphics/jpeg
DEPENDS+=	libltdl>=1.5.24:../../devel/libltdl
DEPENDS+=	imlib2>=1.4.0:../../graphics/imlib2

CONFIGURE_ARGS=	--with-edje-cc=${PREFIX}/bin/edje_cc

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/epsilon/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"
.include	"../../graphics/imlib2/buildlink3.mk"
.include	"../../devel/libltdl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
