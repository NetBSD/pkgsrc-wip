# $NetBSD$

DISTNAME=	terraform-provider-template-2.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/template/
COMMENT=	Terraform template provider
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/${GITHUB_PROJECT}

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

TERRAFORM_PROVIDER_BIN=		terraform-provider-template
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	template

.include "../../lang/go/go-package.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
