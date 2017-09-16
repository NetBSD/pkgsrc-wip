# $NetBSD$

# XXX 0.0.1 is a made-up release number, ask upstream to make a release.
PKGNAME=	go-pass-0.0.1
GITHUB_TAG=	bf9dde6d0d2c004a008c27aaee91170c786f6db8
DISTNAME=	gopass-${GITHUB_TAG}
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=howeyc/}
GITHUB_PROJECT=	gopass

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://github.com/howeyc/gopass
COMMENT=	getpasswd for Go
LICENSE=	isc

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	gopass-${GITHUB_TAG}
GO_SRCPATH=	github.com/howeyc/gopass

.include "../../lang/go/go-package.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
