# $NetBSD$

DISTNAME=	zimpl-3.3.6
CATEGORIES=	math
MASTER_SITES=	https://zimpl.zib.de/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://zimpl.zib.de/download/
COMMENT=	Language to translate the LP models into .lp or .mps
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	bison


.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
