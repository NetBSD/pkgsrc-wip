# $NetBSD$

DISTNAME=	go-kr-text-0.1.0
PKGREVISION=	12
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kr/}
GITHUB_PROJECT=	text
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	Go package for manipulating paragraphs of text
HOMEPAGE=	https://github.com/kr/text
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/kr/text/
GO_DIST_BASE=	text-${PKGVERSION_NOREV}

.include "../../wip/go-pty/buildlink3.mk" # XXX
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
