# $NetBSD: Makefile,v 1.5 2004/07/18 15:50:21 ppostma Exp $
#

DISTNAME=		gtk-theme-switch-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK1 themes.

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch ${PREFIX}/bin/gtk-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 ${PREFIX}/man/man1/gtk-theme-switch.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
