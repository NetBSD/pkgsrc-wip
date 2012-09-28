# $NetBSD: Makefile,v 1.6 2012/09/28 21:28:48 asau Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16menuedit ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
