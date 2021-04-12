# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-kubernetes-2.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/kubernetes/
COMMENT=	Terraform provider for Kubernetes (K8S)
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-kubernetes
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	kubernetes

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} \
	   ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
