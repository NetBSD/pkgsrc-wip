# $NetBSD$

DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	gitea-runner-3.3.0
CATEGORIES=	devel
MASTER_SITES=	https://gitea.com/gitea/runner/archive/
DIST_SUBDIR=	runner

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitea.com/gitea/runner/
COMMENT=	Runner for Gitea based on act
LICENSE=	mit

GO_VERSION_REQD=	126

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} runner gitea-runner

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
