# $NetBSD: Makefile,v 1.3 2004/01/25 02:33:36 grantbeattie Exp $
#

DISTNAME=	sks-${SKS_VERSION}
CATEGORIES=	security
MASTER_SITES=	http://savannah.nongnu.org/download/sks/sks.pkg/${SKS_VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/sks/
COMMENT=	Self Replicating PGP Key Server

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make

SKS_VERSION=	1.0.4

MAKE_ENV+=	LIBDB=-ldb4 BDBINCLUDE=-I${BUILDLINK_DIR}/include BDBLIB=-L${BUILDLINK_DIR}/lib

.include "../../lang/ocaml/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
