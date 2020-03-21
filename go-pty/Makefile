# $NetBSD$

DISTNAME=	go-pty-1.1.1
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kr/}
GITHUB_PROJECT=	pty
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	Go package for using unix pseudo-terminals
HOMEPAGE=	https://github.com/kr/pty
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/kr/pty/
GO_DIST_BASE=	pty-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
