# $NetBSD: Makefile,v 1.2 2005/01/01 22:36:30 mattd Exp $
#

DISTNAME=	matchbox-nest-0.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/projects/matchbox/sources/matchbox-nest/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Matchbox Xnest wrapper

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
