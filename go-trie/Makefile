# $NetBSD$

DISTNAME=	trie-0.0.0.20140408
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=fvbock/}
CATEGORIES=	textproc
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	1d40233c66bdef97a7d978cbe799531a6acf1ea6

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/fvbock/trie
COMMENT=	Trie implementation in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	${HOMEPAGE:S,https://,,}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
