# $NetBSD$

DISTNAME=	flac-eaburns-20170903
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	flac
GITHUB_TAG=	9a6fb92396d1ba6412b82819435dca0b46f959fb
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=eaburns/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eaburns/flac/
COMMENT=	Free Lossless Audio Codec decoder in Go
LICENSE=	mit

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=     github.com/eaburns/${GITHUB_PROJECT}

.include "../../wip/go-bit/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
