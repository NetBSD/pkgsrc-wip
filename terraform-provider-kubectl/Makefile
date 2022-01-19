# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-kubectl-1.13.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=gavinbunney/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/gavinbunney/kubectl
COMMENT=	Terraform provider to handle raw Kubernetes manifest YAML files
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

#UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-kubectl
TERRAFORM_PROVIDER_NAMESPACE=	gavinbunney
TERRAFORM_PROVIDER_TYPE=	kubectl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
