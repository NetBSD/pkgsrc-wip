# $NetBSD: Makefile,v 1.1.1.1 2004/06/21 15:17:33 kibumh Exp $

DISTNAME=		gtkterm2-0.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkterm/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gtkterm.feige.net/
COMMENT=		A simple GTK-2 terminal with tabs

USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	YES

.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
