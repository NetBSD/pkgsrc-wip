# $NetBSD: Makefile,v 1.6 2004/02/16 00:57:49 minskim Exp $
#

DISTNAME=	scew-0.3.1
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.ccd.uab.es/~aleix/scew/

MAINTAINER=	thorbjorn@jemander.net
HOMEPAGE=	http://www.nongnu.org/scew/
COMMENT=	Light-weight DOM-like object model API for Expat

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
