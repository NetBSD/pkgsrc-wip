# $NetBSD$

DISTNAME=	shellescape-1.4.1
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	shellescape
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alessio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alessio/shellescape/
COMMENT=	Escape arbitrary strings for use as command line arguments
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/alessio/shellescape

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
