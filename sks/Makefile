# $NetBSD: Makefile,v 1.4 2004/06/18 21:30:32 thomasklausner Exp $
#

DISTNAME=	sks-1.0.7
CATEGORIES=	security
MASTER_SITES=	http://savannah.nongnu.org/download/sks/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/sks/
COMMENT=	Self Replicating PGP Key Server

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MAKE_ENV+=	LIBDB=-ldb4 BDBINCLUDE=-I${BUILDLINK_DIR}/include BDBLIB=-L${BUILDLINK_DIR}/lib

.include "../../lang/ocaml/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
