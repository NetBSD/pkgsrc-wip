# $NetBSD: Makefile,v 1.1.1.1 2003/05/07 21:57:00 poppnk Exp $
#

DISTNAME=	idesk-0.3.5
CATEGORIES=	x11
MASTER_SITES=	http://linuxhelp.hn.org/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://linuxhelp.hn.org/idesk.php
COMMENT=	Show png icons on your desktop

USE_GMAKE=	yes
USE_X11=	yes
USE_BUILDLINK2=	yes
#MAKE_ENV+=	PREFIX=${PREFIX}

.include "../../graphics/imlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
