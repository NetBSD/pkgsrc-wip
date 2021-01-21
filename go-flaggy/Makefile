# $NetBSD$

DISTNAME=	go-flaggy-1.4.4
GITHUB_PROJECT=	flaggy
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=integrii/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/integrii/flaggy/
COMMENT=	Idiomatic Go input parsing with subcommands, positional values
LICENSE=	unlicense

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/integrii/flaggy

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
