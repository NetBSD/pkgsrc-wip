# $NetBSD$
#
# This file implements common logic for Terraform providers in pkgsrc.
#
# Please note that if the provided `do-install:' should be used this file
# should be included before including lang/go/go-package.mk or
# lang/go/go-module.mk.
#
# === Package-settable variables ===
#
# TERRAFORM_PROVIDER_REGISTRY (optional)
#
# TERRAFORM_PROVIDER_BIN
#
# TERRAFORM_PROVIDER_NAME
#
# TERRAFORM_PROVIDER_VERSION
#
# TERRAFORM_PROVIDER_DIR (optional)
#
# Keywords: terraform
#

.include "../../wip/terraform/version.mk"

DEPENDS+=	${TERRAFORM_PACKAGE_DEP}

TERRAFORM_PROVIDER_REGISTRY?=	registry.terraform.io
TERRAFORM_PROVIDER_VERSION?=	${PKGVERSION_NOREV}
TERRAFORM_PROVIDER_DIR?=	share/terraform/plugins/${TERRFORM_PROVIDER_REGISTRY}/${TERRAFORM_PROVIDER_NAME}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}

PLIST_SUBST+=		TERRAFORM_PROVIDER_NAME=${TERRAFORM_PROVIDER_NAME}
PLIST_SUBST+=		TERRAFORM_PROVIDER_VERSION=${TERRAFORM_PROVIDER_VERSION}

PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_NAME}", "$${TERRAFORM_PROVIDER_NAME}") }
PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_VERSION}", "$${TERRAFORM_PROVIDER_VERSION}") }

INSTALLATION_DIRS?=	${TERRAFORM_PROVIDER_DIR}

.if !target(do-install)
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} \
	    ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR}
.endif
