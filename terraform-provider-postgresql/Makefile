# $NetBSD$

DISTNAME=	terraform-provider-postgresql-1.11.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cyrilgdn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/cyrilgdn/postgresql/
COMMENT=	Terraform PostgreSQL provider
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-aws
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	aws

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
