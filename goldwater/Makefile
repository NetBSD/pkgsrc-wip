# $NetBSD: Makefile,v 1.3 2004/05/02 21:08:23 blef Exp $
#

DISTNAME=		goldwater-1.4.0
CATEGORIES=		wip
MASTER_SITES=		http://www.nfluid.com/download/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nfluid.com/download/src/
COMMENT=		Highly scalable distributed middleware

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/phlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
