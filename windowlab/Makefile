# $NetBSD: Makefile,v 1.1.1.1 2003/04/20 23:36:12 xtraeme Exp $
#

DISTNAME=	windowlab-1.09
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager, based on aewm

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
