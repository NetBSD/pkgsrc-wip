# $NetBSD: Makefile,v 1.4 2004/07/18 15:50:21 ppostma Exp $
#

DISTNAME=		goldwater-1.4.0
CATEGORIES=		sysutils
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
