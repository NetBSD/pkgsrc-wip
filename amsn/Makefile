# $NetBSD: Makefile,v 1.3 2003/09/06 11:30:37 cjep Exp $
#

DISTNAME=	amsn-0.71
WRKSRC=		${WRKDIR}/msn
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://amsn.sf.net/
COMMENT=	Alvaro's MSN messenger client

USE_BUILDLINK2=	YES

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
