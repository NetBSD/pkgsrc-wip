# $NetBSD: Makefile,v 1.2 2003/06/16 21:57:29 virtus Exp $
#

DISTNAME=	rosegarden-4-0.9.1
CATEGORIES=	audio	
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.all-day-breakfast.cm/rosegarden/
COMMENT=	Development release of rosegarden

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-qt-dir=/usr/X11R6/qt3

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
