# $NetBSD: Makefile,v 1.1.1.1 2004/03/19 10:52:34 xtraeme Exp $
#

DISTNAME=		matchbox-panel-manager-0.1
CATEGORIES=		x11
MASTER_SITES=		http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://matchbox.handhelds.org/sources/matchbox-panel-manager/0.1/
COMMENT=		Handles Matchbox's window manager panels		

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
