# $NetBSD$

DISTNAME=	terraform-provider-google-6.20.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/terraform-provider-google/
COMMENT=	Terraform provider for Google Cloud Platform
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-google
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	google

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
