# $NetBSD: Makefile,v 1.6 2005/04/11 21:15:29 tvierling Exp $
#

DISTNAME=	rosegarden-4-0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	Development release of rosegarden

USE_X11=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-qt-dir=/usr/X11R6/qt3

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
