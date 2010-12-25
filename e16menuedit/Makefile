# $NetBSD: Makefile,v 1.5 2010/12/25 12:45:45 noud4 Exp $
#

DISTNAME=		e16menuedit-0.1
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Menu editor for Enlightenment

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

USE_LIBTOOL=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16menuedit ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
