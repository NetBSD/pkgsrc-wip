# $NetBSD: Makefile,v 1.7 2006/05/01 01:32:00 shattered Exp $
#

DISTNAME=		edje-0.5.0
CATEGORIES=		graphics x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/Libraries/Edje/
COMMENT=		Complex Graphical Design/Layout Engine

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../wip/embryo/buildlink3.mk"
.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
