# $NetBSD: Makefile,v 1.1.1.1 2003/04/16 16:03:57 xtraeme Exp $
#

DISTNAME=	pixieplus-0.5.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.mosfet.org/pixie/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.mosfet.org/pixie/
COMMENT=	Free, fast, and feature packed image browse for KDE

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
