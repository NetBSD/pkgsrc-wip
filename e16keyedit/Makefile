# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:40 tvierling Exp $
#

DISTNAME=		e16keyedit-0.2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Keys setup program for Enlightenment

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

USE_LIBTOOL=		YES
USE_X11=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16keyedit ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
