# $NetBSD: Makefile,v 1.3 2004/10/15 14:53:20 tvierling Exp $
#

DISTNAME=		evas-1.0.0_pre13
PKGNAME=		evas-1.0.0
PKGREVISION=		1
CATEGORIES=		wip x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/pages/evas.html
COMMENT=		High level display-independent canvas API

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/edb/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
