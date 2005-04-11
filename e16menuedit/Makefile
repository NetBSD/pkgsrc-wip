# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:40 tvierling Exp $
#

DISTNAME=		e16menuedit-0.1
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Menu editor for Enlightenment

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

USE_LIBTOOL=		YES
USE_X11=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16menuedit ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
