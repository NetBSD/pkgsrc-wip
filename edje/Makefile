# $NetBSD: Makefile,v 1.1.1.1 2004/09/16 17:41:00 airhead Exp $
#

DISTNAME=		edje-0.5.0
CATEGORIES=		wip graphics x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/pages/edje.html
COMMENT=		Complex Graphical Design/Layout Engine

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

.include "../../devel/libtool/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/embryo/buildlink3.mk"
.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
