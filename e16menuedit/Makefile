# $NetBSD: Makefile,v 1.4 2010/12/24 16:18:47 noud4 Exp $
#

DISTNAME=		e16menuedit-0.1
PKGREVISION=		1
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
.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
