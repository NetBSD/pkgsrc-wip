# $NetBSD: Makefile,v 1.13 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-aws-modules-http-2.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-aws-modules/}
GITHUB_PROJECT=	terraform-provider-http
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/terraform-aws-modules/http/latest
COMMENT=	Terraform provider for interacting with generic HTTP servers
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-http
TERRAFORM_PROVIDER_NAMESPACE=	terraform-aws-modules
TERRAFORM_PROVIDER_TYPE=	http

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
