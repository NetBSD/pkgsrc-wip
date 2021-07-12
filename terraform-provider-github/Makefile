# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-github-4.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=integrations/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/github/
COMMENT=	Terraform provider for GitHub resources
LICENSE=	mit

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-github
TERRAFORM_PROVIDER_NAMESPACE=	integrations
TERRAFORM_PROVIDER_TYPE=	github

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
