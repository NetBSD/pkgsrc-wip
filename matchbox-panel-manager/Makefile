# $NetBSD: Makefile,v 1.3 2004/03/20 17:21:38 xtraeme Exp $
#

DISTNAME=	matchbox-panel-manager-0.1
CATEGORIES=	x11
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
COMMENT=	Manager panel for the Matchbox desktop

DEPENDS+=	gnome2-dirs>=1.5:../../misc/gnome2-dirs

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
