# $NetBSD: Makefile,v 1.11 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-null-3.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/null/
COMMENT=	Terraform provider for nothing
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/terraform-providers/${GITHUB_PROJECT}

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

TERRAFORM_PROVIDER_BIN=		terraform-provider-null
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	null

.include "../../lang/go/go-package.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
