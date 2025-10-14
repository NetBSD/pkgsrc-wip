# $NetBSD$

DISTNAME=	zk-0.15.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=zk-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zk-org.github.io/zk/
COMMENT=	Plain text note-taking assistant
LICENSE=	gnu-gpl-v3

GO_BUILD_PATTERN+=	-tags "fts5" \
			-ldflags ' \
			-X main.Version=${GITHUB_TAG}'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
