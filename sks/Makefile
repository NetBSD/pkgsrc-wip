# $NetBSD: Makefile,v 1.1.1.1 2003/10/28 21:27:14 cubidou Exp $
#

DISTNAME=	sks-${SKS_VERSION}
CATEGORIES=	security
MASTER_SITES=	http://savannah.nongnu.org/download/sks/sks.pkg/${SKS_VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.nongnu.org/sks/
COMMENT=	Self Replicating PGP Key Server

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

SKS_VERSION=	1.0.4

MAKE_ENV+=	LIBDB=-ldb4 BDBINCLUDE=-I${BUILDLINK_DIR}/include BDBLIB=-L${BUILDLINK_DIR}/lib

.include "../../lang/ocaml/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
