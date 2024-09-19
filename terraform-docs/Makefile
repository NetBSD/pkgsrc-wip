# $NetBSD: Makefile,v 1.16 2021/01/27 13:35:58 leot Exp $

DISTNAME=	terraform-docs-0.12.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-docs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://terraform-docs.io/
COMMENT=	Generate documentation from Terraform modules
LICENSE=	mit

# TODO: find a way to extract/hardcode commitHash/buildDate
GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/terraform-docs/terraform-docs/internal/version.version=v${PKGVERSION_NOREV} \
			-X github.com/terraform-docs/terraform-docs/internal/version.commitHash="" \
			-X github.com/terraform-docs/terraform-docs/internal/version.buildDate=""'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
