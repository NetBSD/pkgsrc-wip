# $NetBSD: Makefile,v 1.5 2004/05/09 22:32:05 blef Exp $
#

DISTNAME=	rosegarden-4-0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	Development release of rosegarden

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-qt-dir=/usr/X11R6/qt3

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
