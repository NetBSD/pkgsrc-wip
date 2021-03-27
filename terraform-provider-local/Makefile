# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-local-2.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/local/
COMMENT=	Terraform provider for local resources
LICENSE=	mpl-2.0

DEPENDS+=	terraform-[0-9]*:../../net/terraform

GO_BUILD_PATTERN=	.

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_REGISTRY=	registry.terraform.io
TERRAFORM_PROVIDER_NAME=	hashicorp/local
TERRAFORM_PROVIDER_VERSION=	${PKGVERSION_NOREV}
TERRAFORM_PROVIDER_DIR=		share/terraform/plugins/${TERRFORM_PROVIDER_REGISTRY}/${TERRAFORM_PROVIDER_NAME}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}

PLIST_SUBST+=		TERRAFORM_PROVIDER_NAME=${TERRAFORM_PROVIDER_NAME}
PLIST_SUBST+=		TERRAFORM_PROVIDER_VERSION=${TERRAFORM_PROVIDER_VERSION}

PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_NAME}", "$${TERRAFORM_PROVIDER_NAME}") }
PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_VERSION}", "$${TERRAFORM_PROVIDER_VERSION}") }

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/terraform-provider-local \
	    ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
