# $NetBSD: Makefile,v 1.2 2003/05/07 23:59:08 xtraeme Exp $
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

.include "../../graphics/imlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
