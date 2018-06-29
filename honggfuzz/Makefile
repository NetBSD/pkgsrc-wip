# $NetBSD$

DISTNAME=	honggfuzz-1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	tomsun.0.7@gmail.com
HOMEPAGE=	https://github.com/google/honggfuzz/
COMMENT=	Security oriented fuzzer based on code coverage
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run gmake

.include "../../lang/libBlocksRuntime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
