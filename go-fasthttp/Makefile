# $NetBSD$

DISTNAME=		go-fasthttp-${GITHUB_TAG}
PKGNAME=		go-fasthttp-1.3.0
GITHUB_PROJECT=		fasthttp
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=valyala/}
GITHUB_TAG=		46469b532d0621287a2184a890564a59a3d528f3

MAINTAINER=		ng0@n0.is
HOMEPAGE=		https://github.com/valyala/fasthttp/
COMMENT=		Fast HTTP package for Go
LICENSE=		mit

GO_SRCPATH=		github.com/valyala/fasthttp
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../wip/go-bytebufferpool/buildlink3.mk"
.include "../../wip/go-tcplisten/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-cpuid/buildlink3.mk"
.include "../../wip/go-compress/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
