# $NetBSD$

DISTNAME=	sops-3.7.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/sops
COMMENT=	Simple and flexible tool for managing secrets
LICENSE=	mpl-2.0

GO_BUILD_PATTERN+=	./cmd/sops

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
