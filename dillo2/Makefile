# $NetBSD: Makefile,v 1.1.1.1 2008/10/15 18:34:18 christtrekker Exp $
#

DISTNAME=	dillo-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.dillo.org/
COMMENT=	Very small and fast graphical web browser using FLTK2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/fltk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
