# $NetBSD: Makefile,v 1.2 2004/01/25 02:22:59 grantbeattie Exp $
#

DISTNAME=		goldwater-1.4.0
CATEGORIES=		wip
MASTER_SITES=		http://www.nfluid.com/download/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nfluid.com/download/src/
COMMENT=		Highly scalable distributed middleware

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../textproc/expat/buildlink2.mk"
.include "../../wip/phlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
