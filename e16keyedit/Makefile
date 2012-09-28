# $NetBSD: Makefile,v 1.6 2012/09/28 21:26:32 asau Exp $
#

DISTNAME=		e16keyedit-0.2
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Keys setup program for Enlightenment

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

USE_LIBTOOL=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e16keyedit ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
