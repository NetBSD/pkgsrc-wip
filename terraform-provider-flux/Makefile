# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-flux-0.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fluxcd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/fluxcd/flux/latest
COMMENT=	Terraform provider for Flux version 2
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-flux
TERRAFORM_PROVIDER_NAMESPACE=	fluxcd
TERRAFORM_PROVIDER_TYPE=	flux

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
