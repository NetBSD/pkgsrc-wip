# $NetBSD: Makefile,v 1.5 2004/05/07 01:58:10 xtraeme Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
CATEGORIES=	x11
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
COMMENT=	Manager panel for the Matchbox desktop

USE_BUILDLINK3=	yes
USE_DIRS+=	gnome2-1.5
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
