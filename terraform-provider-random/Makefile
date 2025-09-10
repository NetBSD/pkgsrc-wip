# $NetBSD: Makefile,v 1.13 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-random-3.6.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/random/
COMMENT=	Terraform provider for randomness
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-random
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	random

TERRAFORM_PROVIDER_LEGACY_INSTALL=	yes

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/terraform-providers/${GITHUB_PROJECT}

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
