# $NetBSD: Makefile,v 1.2 2004/03/20 14:04:38 xtraeme Exp $
#

DISTNAME=	matchbox-common-0.8
CATEGORIES=	wm
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-common/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/sources/matchbox-common/0.8/
COMMENT=	Pixmaps for the Matchbox window manager

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
