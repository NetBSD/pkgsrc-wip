# $NetBSD: Makefile,v 1.1.1.1 2004/09/16 15:57:51 airhead Exp $
#

DISTNAME=		epeg-0.9.0
CATEGORIES=		wip graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/pages/epeg.html
COMMENT=		Fast JPEG scaling library for thumbnail generation

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

.include "../../devel/libtool/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
