# $NetBSD: Makefile,v 1.1.1.1 2004/01/05 18:42:04 poppnk Exp $
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
USE_GMAKE=		yes

.include "../../textproc/expat/buildlink2.mk"
.include "../../wip/phlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
