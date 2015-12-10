# $NetBSD$

PKGNAME=	ldc-0.16.1
CATEGORIES=	wip

GIT_REPOSITORIES=	ldc
GIT_REPO.ldc=	https://github.com/ldc-developers/ldc.git
#GIT_TAG.ldc=	v0.16.1
GIT_BRANCH.ldc=	release-0.16.1
WRKSRC=	${WRKDIR}/ldc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.dlang.org/LDC
COMMENT=	D compiler based on LLVM
#LICENSE=	# TODO: (see mk/license.mk)

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/llvm-git/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
