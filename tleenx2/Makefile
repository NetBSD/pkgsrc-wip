# $NetBSD: Makefile,v 1.6 2005/07/27 16:31:20 thomasklausner Exp $
#

DISTNAME=	TleenX2-20040214
PKGNAME=	tleenx2-20040214
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tleenx/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tleenx.sourceforge.net/
COMMENT=	Client to tlen.pl - polish IM / chat system

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBS+=			-lm

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
