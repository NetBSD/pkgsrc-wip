# $NetBSD: Makefile,v 1.6 2004/01/15 17:26:22 virtus Exp $
#

DISTNAME=	amsn-0_83
WRKSRC=		${WRKDIR}/msn
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://amsn.sourceforge.net/
COMMENT=	Alvaro's MSN messenger client

USE_BUILDLINK2=	YES

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
