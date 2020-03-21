# $NetBSD$

DISTNAME=	madonctl-2.3.1
PKGREVISION=	12
CATEGORIES=	net chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=McKael/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://lilotux.net/~mikael/pub/madonctl/
COMMENT=	Command line client for the Mastodon distributed social network API
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/McKael/madonctl/
GO_DIST_BASE=	${DISTNAME}

.include "../../lang/go/go-package.mk"
.include "../../devel/go-cobra/buildlink3.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../devel/go-isatty/buildlink3.mk"
.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-viper/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.include "../../wip/go-madon/buildlink3.mk" # XXX
.include "../../wip/go-ghodss-yaml/buildlink3.mk" # XXX
.include "../../wip/go-kr-text/buildlink3.mk" # XXX
.include "../../mk/bsd.pkg.mk"
