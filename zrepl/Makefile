# $NetBSD$

GITHUB_PROJECT=	zrepl
GITHUB_TAG=	refs/tags/v0.5.0
DISTNAME=	v0.5.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=zrepl/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zrepl/zrepl/
COMMENT=	One-stop ZFS backup & replication solution
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME}

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/zrepl/zrepl/version.zreplVersion=${DISTNAME:S,^v,,}'

GO_BUILD_PATTERN+=	-mod=readonly .

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
