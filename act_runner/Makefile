# $NetBSD$

DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	act_runner-0.2.13
CATEGORIES=	devel
MASTER_SITES=	https://gitea.com/gitea/act_runner/archive/
DIST_SUBDIR=	act_runner

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitea.com/gitea/act_runner/
COMMENT=	Runner for Gitea based on act
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGBASE}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
