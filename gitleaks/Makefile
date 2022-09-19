# $NetBSD: Makefile,v 1.5 2022/09/17 11:03:56 leot Exp $

DISTNAME=	gitleaks-8.12.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=zricethezav/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitleaks.io/
COMMENT=	Protect and discover leaked secrets
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/zricethezav/gitleaks/v8/cmd.Version=${GITHUB_TAG}'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
