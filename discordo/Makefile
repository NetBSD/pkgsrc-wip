# $NetBSD: Makefile,v 1.15 2024/02/07 14:50:50 bsiegert Exp $

DISTNAME=	discordo-0.0.0.20240221
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ayn2op/}
GITHUB_TAG=	3486f6ced9db8eb865641632e50daa2550a55ef8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ayn2op/discordo
COMMENT=	Lightweight, secure, and feature-rich Discord terminal client
LICENSE=	mit

#GO_BUILD_PATTERN+=	-ldflags ' \
#			-X github.com/styrainc/regal/pkg/version.Version=${GITHUB_TAG} \
#			-X github.com/styrainc/regal/pkg/version.Commit= \
#			-X github.com/styrainc/regal/pkg/version.Timestamp= \
#			-X github.com/styrainc/regal/pkg/version.Hostname='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
