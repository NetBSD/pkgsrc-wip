# $NetBSD$

DISTNAME=	terraform-provider-scaleway-2.58.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=scaleway/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/scaleway/
COMMENT=	Terraform provider for Scaleway
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-scaleway
TERRAFORM_PROVIDER_NAMESPACE=	scaleway
TERRAFORM_PROVIDER_TYPE=	scaleway

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
