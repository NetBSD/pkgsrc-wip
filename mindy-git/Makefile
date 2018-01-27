# $NetBSD$

DISTNAME=		mindy-0.0.0
CATEGORIES=		lang
GIT_REPOSITORIES=	mindy
GIT_REPO.mindy=		https://github.com/project-mindy/mindy.git

WRKSRC=		${WRKDIR}/mindy

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/project-mindy/mindy
COMMENT=	Mindy Is Not Dylan Yet
#LICENSE=	# TODO: (see mk/license.mk)

USE_CMAKE=	yes
USE_TOOLS+=	cmake

.include "../../wip/mk/git-package.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
