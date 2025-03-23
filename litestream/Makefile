# $NetBSD$

DISTNAME=	litestream-0.3.13
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=benbjohnson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://litestream.io/
COMMENT=	Streaming replication for SQLite
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.Version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/litestream

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	cmd/litestream/main_notwindows.go
SUBST_STAGE.paths=	post-configure
SUBST_VARS.paths+=	PKG_SYSCONFDIR

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
