# $NetBSD$

DISTNAME=	go-mpb-5.4.0
GITHUB_PROJECT=	mpb
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=vbauerster/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/vbauerster/mpb/
COMMENT=	Multi progress bar for Go cli applications
LICENSE=	unlicense

GO_SRCPATH=	github.com/vbauerster/mpb
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/go-sys/buildlink3.mk"
.include "../../wip/go-ewma/buildlink3.mk"
.include "../../wip/go-stripansi/buildlink3.mk"
.include "../../textproc/go-runewidth/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
