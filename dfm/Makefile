# $NetBSD: Makefile,v 1.3 2004/02/27 23:26:20 rillig Exp $
#

DISTNAME=	dfm-0.99.9
CATEGORIES=	x11
MASTER_SITES=   http://www.kaisersite.de/dfm/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.kaisersite.de/dfm/
COMMENT=	File Manager for Linux and other UNIX like OSs

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

WRKSRC=		${WRKDIR}/dfm

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
