# $NetBSD: Makefile,v 1.4 2004/04/14 21:33:02 poppnk Exp $
#

DISTNAME=			dfm-0.99.9
CATEGORIES=			x11
MASTER_SITES=   	http://www.kaisersite.de/dfm/

MAINTAINER=			pancake@phreaker.net
HOMEPAGE=			http://www.kaisersite.de/dfm/
COMMENT=			File Manager for Linux and other UNIX like OSs

USE_BUILDLINK3=		YES
USE_X11=			YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

WRKSRC=		${WRKDIR}/dfm

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
