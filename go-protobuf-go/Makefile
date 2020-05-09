# $NetBSD$

DISTNAME=	go-protobuf-go-1.22.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}
GITHUB_PROJECT=	protobuf-go
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/protocolbuffers/protobuf-go
COMMENT=	Go support for Google\'s protocol buffers
LICENSE=	modified-bsd

CONFLICTS=	go-protobuf-[0-9]*
EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	google.golang.org/protobuf

.include "../../devel/go-cmp/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
