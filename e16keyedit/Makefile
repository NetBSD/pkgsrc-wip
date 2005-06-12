# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:16 kristerw Exp $
#

DISTNAME=		e16keyedit-0.2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Keys setup program for Enlightenment

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

USE_LIBTOOL=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16keyedit ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
