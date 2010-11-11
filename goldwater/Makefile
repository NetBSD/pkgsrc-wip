# $NetBSD: Makefile,v 1.7 2010/11/11 22:42:06 shattered Exp $
#

DISTNAME=		goldwater-1.4.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.zxdesign.info/download/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.zxdesign.info/download/src/
COMMENT=		Highly scalable distributed middleware

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/phlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
