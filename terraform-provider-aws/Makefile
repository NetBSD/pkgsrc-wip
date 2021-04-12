# $NetBSD: Makefile,v 1.25 2021/03/19 17:37:03 bsiegert Exp $

DISTNAME=	terraform-provider-aws-3.36.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-providers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/docs/providers/aws/
COMMENT=	Terraform provider for Amazon Web Services
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

UNLIMIT_RESOURCES=	datasize virtualsize

TERRAFORM_PROVIDER_BIN=		terraform-provider-aws
TERRAFORM_PROVIDER_NAMESPACE=	hashicorp
TERRAFORM_PROVIDER_TYPE=	aws

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} \
	   ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
