# $NetBSD: Makefile,v 1.12 2021/02/01 16:54:00 tpaul Exp $

DISTNAME=	terraform-provider-kubernetes-1.13.3
PKGNAME=	${DISTNAME:S/kubernetes/kubernetes1/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform-provider-kubernetes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/kubernetes/
COMMENT=	Terraform provider for Kubernetes (K8S)
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-kubernetes
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	kubernetes

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/${GITHUB_PROJECT}

GO_BUILD_PATTERN=	${GO_SRCPATH}/.

USE_TOOLS+=	bash
REPLACE_BASH+=	scripts/*.sh

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${TERRAFORM_PROVIDER_BIN} \
	   ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}

.include "../../lang/go/go-package.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
