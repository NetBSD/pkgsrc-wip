# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-time-0.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/time/
COMMENT=	Terraform provider for Time-Based Resources
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-time
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	time

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
