# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 22:45:38 virtus Exp $
#

DISTNAME=	amsn-0.71
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://amsn.sf.net
COMMENT=	Alvaro's MSN messenger client

WRKSRC=		${WRKDIR}/msn
USE_BUILDLINK2=	YES

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
