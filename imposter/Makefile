# $NetBSD: Makefile,v 1.1.1.1 2004/02/15 23:15:48 poppnk Exp $
#

DISTNAME=	imposter-0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11=		YES
USE_GNU_TOOLS+=		make

.include "../../devel/glib2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
