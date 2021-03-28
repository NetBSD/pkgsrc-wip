# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-local-2.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/local/
COMMENT=	Terraform provider for local resources
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-local
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	local

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} \
	   ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
