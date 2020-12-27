# $NetBSD$

DISTNAME=	circbuf-0.0.14022019
PKGNAME=	go-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=armon/}
GITHUB_TAG=	5111143e8da2e98b4ea6a8f32b9065ea1821c191
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kiaderouiche/circbuf/
COMMENT=	Golang circular (ring) buffer
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/kr/fs

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
