# $NetBSD$

DISTNAME=	go-cyclo-0.3.1
GITHUB_PROJECT=	gocyclo
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fzipp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/fzipp/gocyclo/
COMMENT=	Calculate cyclomatic complexities of functions in Go source code
LICENSE=	2-clause-bsd

GO_SRCPATH=     github.com/fzipp/gocyclo
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
