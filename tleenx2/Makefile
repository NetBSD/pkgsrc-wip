# $NetBSD: Makefile,v 1.4 2004/02/22 21:48:21 minskim Exp $
#

DISTNAME=	TleenX2-20040214
PKGNAME=	tleenx2-20040214
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tleenx/}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://tleenx.sourceforge.net/
COMMENT=	Client to tlen.pl - polish IM / chat system

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBS+=			-lm

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
