# $NetBSD$

PKGNAME=	honggfuzz-1.6
CATEGORIES=	devel

GIT_REPOSITORIES=	honggfuzz
GIT_REPO.honggfuzz=	https://github.com/google/honggfuzz.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/honggfuzz/
COMMENT=	Security oriented fuzzer based on code coverage
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/honggfuzz

USE_TOOLS+=	bash:run gmake

.include "../../wip/mk/git-package.mk"
.include "../../lang/libBlocksRuntime/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
