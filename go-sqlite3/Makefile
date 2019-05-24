# $NetBSD$

DISTNAME=		go-sqlite3-${GITHUB_TAG}
PKGNAME=		go-sqlite3-1.10.0
GITHUB_PROJECT=		go-sqlite3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mattn/}
GITHUB_TAG=		c7c4067b79cc51e6dfdcef5c702e74b1e0fa7c75

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/mattn/go-sqlite3
COMMENT=		Sqlite3 driver for Go using database/sql
LICENSE=		mit

GO_SRCPATH=		github.com/mattn/go-sqlite3
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

MAKE_ENV+=		CGO_ENABLED=1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
