# $NetBSD: Makefile,v 1.1.1.1 2003/05/15 20:22:11 cubidou Exp $
#

DISTNAME=	dosbox-0.58
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	multi-platform DOS emulator using SDL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
