# $NetBSD: Makefile,v 1.7 2004/05/01 16:35:57 blef Exp $
#

DISTNAME=	amsn-0_83
WRKSRC=		${WRKDIR}/msn
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://amsn.sourceforge.net/
COMMENT=	Alvaro's MSN messenger client

USE_BUILDLINK3=	YES

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
