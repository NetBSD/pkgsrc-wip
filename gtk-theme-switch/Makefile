# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:03 grantbeattie Exp $
#

DISTNAME=		gtk-theme-switch-1.0.1
CATEGORIES=		wip
MASTER_SITES=		http://www.muhri.net/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.muhri.net/
COMMENT=		Allows quick & easy switching of GTK1 themes.

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/switch ${PREFIX}/bin/gtk-theme-switch
	${INSTALL_MAN} ${WRKSRC}/switch.1 ${PREFIX}/man/man1/gtk-theme-switch.1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
