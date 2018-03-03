# $NetBSD$

DISTNAME=	will-it-scale-0
CATEGORIES=	benchmarks
GIT_REPO=	git@github.com:antonblanchard/will-it-scale.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/antonblanchard/will-it-scale/
COMMENT=	hwloc benchmark
#LICENSE=	# none

USE_TOOLS+=	gmake

.include "../../wip/mk/git-package.mk"

.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
