# $NetBSD$

DISTNAME=	terraform-provider-vultr-2.22.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/vultr/
COMMENT=	Terraform Vultr provider
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-vultr
TERRAFORM_PROVIDER_NAMESPACE=	vultr
TERRAFORM_PROVIDER_TYPE=	vultr

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
