# $NetBSD$

DISTNAME=	terraform-provider-gandi-2.3.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-gandi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/go-gandi/terraform-provider-gandi/
COMMENT=	Terraform provider for Gandi
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-gandi
TERRAFORM_PROVIDER_NAMESPACE=	go-gandi
TERRAFORM_PROVIDER_TYPE=	gandi

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
