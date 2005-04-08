# $NetBSD: Makefile,v 1.3 2005/04/08 15:30:05 bencollver Exp $
#

DISTNAME=	matchbox-nest-0.3
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-nest/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Matchbox Xnest wrapper

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
