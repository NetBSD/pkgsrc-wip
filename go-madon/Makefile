# $NetBSD$

DISTNAME=	go-madon-2.3.0
PKGREVISION=	12
CATEGORIES=	devel net chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=McKael/}
GITHUB_PROJECT=	madon
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/McKael/madon
COMMENT=	Golang library for the Mastodon API
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/McKael/madon/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../net/go-websocket/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.include "../../wip/go-rest/buildlink3.mk" # XXX
.include "../../mk/bsd.pkg.mk"
