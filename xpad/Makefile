# $NetBSD: Makefile,v 1.2 2003/07/15 21:27:17 xtraeme Exp $
#

DISTNAME=	xpad-1.10.1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpad/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://xpad.sourceforge.net/
COMMENT=	Sticky note application in GTK 2

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
