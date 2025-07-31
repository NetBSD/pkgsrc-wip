# $NetBSD: Makefile,v 1.25 2021/03/19 17:37:03 bsiegert Exp $

DISTNAME=	terraform-provider-hcloud-1.52.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hetznercloud/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/hcloud/
COMMENT=	Terraform Hetzner Cloud provider
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-hcloud
TERRAFORM_PROVIDER_NAMESPACE=	hetznercloud
TERRAFORM_PROVIDER_TYPE=	hcloud

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
