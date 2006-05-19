# $NetBSD: Makefile,v 1.11 2006/05/19 16:51:18 ykomatsu Exp $
#

DISTNAME=		gtk-theme-switch-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK1 themes

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch ${PREFIX}/bin/gtk-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 ${PREFIX}/${PKGMANDIR}/man1/gtk-theme-switch.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
