# $NetBSD$
#
# This file implements common logic for Terraform providers in pkgsrc.
#
# Package-settable variables:
#
# TERRAFORM_PROVIDER_HOSTNAME (optional)
#	Hostname of the Terraform registry that distributes the provider.
#
#	Default: registry.terraform.io
#
# OPENTOFU_PROVIDER_HOSTNAME (optional)
#	Hostname of the OpenTofu registry that distributes the provider.
#
#	Default: registry.opentofu.org
#
# TERRAFORM_PROVIDER_BIN
#	Binary name of the provider that will be installed under
#       TERRAFORM_PROVIDER_DIR.
#
# TERRAFORM_PROVIDER_NAMESPACE
#	Organizational namespace within the Terraform registry.
#
# TERRAFORM_PROVIDER_TYPE
#	Short name for the platform or system the provider manages.
#
# TERRAFORM_PROVIDER_VERSION (optional)
#	Version of the provider.
#
#	Default: ${PKGVERSION_NOREV}
#
# TERRAFORM_PROVIDER_DIR (optional)
#	Directory where the provider will be installed.
#
#	Default: share/terraform/plugins/${TERRAFORM_PROVIDER_HOSTNAME}/${TERRAFORM_PROVIDER_NAMESPACE}/${TERRAFORM_PROVIDER_TYPE}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}
#
# OPENTOFU_PROVIDER_DIR (optional)
#	Directory where the provider will be installed.
#
#	Default: share/terraform/plugins/${OPENTOFU_PROVIDER_HOSTNAME}/${TERRAFORM_PROVIDER_NAMESPACE}/${TERRAFORM_PROVIDER_TYPE}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}
#
# Keywords: terraform
#

.include "../../wip/terraform/version.mk"

DEPENDS+=	${TERRAFORM_PACKAGE_DEP}

TERRAFORM_PROVIDER_HOSTNAME?=	registry.terraform.io
TERRAFORM_PROVIDER_VERSION?=	${PKGVERSION_NOREV}
TERRAFORM_PROVIDER_DIR?=	share/terraform/plugins/${TERRAFORM_PROVIDER_HOSTNAME}/${TERRAFORM_PROVIDER_NAMESPACE}/${TERRAFORM_PROVIDER_TYPE}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}

OPENTOFU_PROVIDER_HOSTNAME?=	registry.opentofu.org
OPENTOFU_PROVIDER_DIR?=		share/terraform/plugins/${OPENTOFU_PROVIDER_HOSTNAME}/${TERRAFORM_PROVIDER_NAMESPACE}/${TERRAFORM_PROVIDER_TYPE}/${TERRAFORM_PROVIDER_VERSION}/${GO_PLATFORM}

PLIST_SUBST+=		TERRAFORM_PROVIDER_HOSTNAME=${TERRAFORM_PROVIDER_HOSTNAME}
PLIST_SUBST+=		TERRAFORM_PROVIDER_NAMESPACE=${TERRAFORM_PROVIDER_NAMESPACE}
PLIST_SUBST+=		TERRAFORM_PROVIDER_TYPE=${TERRAFORM_PROVIDER_TYPE}
PLIST_SUBST+=		TERRAFORM_PROVIDER_VERSION=${TERRAFORM_PROVIDER_VERSION}

PLIST_SUBST+=		OPENTOFU_PROVIDER_HOSTNAME=${OPENTOFU_PROVIDER_HOSTNAME}

PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_HOSTNAME}", "$${TERRAFORM_PROVIDER_HOSTNAME}") }
PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_NAMESPACE}", "$${TERRAFORM_PROVIDER_NAMESPACE}") }
PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_TYPE}", "$${TERRAFORM_PROVIDER_TYPE}") }
PRINT_PLIST_AWK+=	{ sub("${TERRAFORM_PROVIDER_VERSION}", "$${TERRAFORM_PROVIDER_VERSION}") }

PRINT_PLIST_AWK+=	{ sub("${OPENTOFU_PROVIDER_HOSTNAME}", "$${OPENTOFU_PROVIDER_HOSTNAME}") }

INSTALLATION_DIRS+=	${TERRAFORM_PROVIDER_DIR}
INSTALLATION_DIRS+=	${OPENTOFU_PROVIDER_DIR}

#
# This should be overwritten via `do-install:' target, however
# lang/go/go-{module,package}.mk already overwrite them.
#
.if !target(pre-install)
pre-install:
	${RUN} \
	if [ -f ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} ]; then \
		${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/${TERRAFORM_PROVIDER_BIN} \
		    ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR} ; \
		${LN} -sf ${PREFIX}/${TERRAFORM_PROVIDER_DIR}/${TERRAFORM_PROVIDER_BIN} \
		    ${DESTDIR}${PREFIX}/${OPENTOFU_PROVIDER_DIR}/${TERRAFORM_PROVIDER_BIN} ; \
		{ [ -d ${WRKDIR}/.gopath ] && chmod -R +w ${WRKDIR}/.gopath || ${TRUE} ; } ; \
		${RM} -rf ${WRKDIR}/.gopath/bin ; \
	elif [ -f ${WRKDIR}/bin/${TERRAFORM_PROVIDER_BIN} ]; then \
		${INSTALL_PROGRAM} ${WRKDIR}/bin/${TERRAFORM_PROVIDER_BIN} \
		    ${DESTDIR}${PREFIX}/${TERRAFORM_PROVIDER_DIR} ; \
		${LN} -sf ${PREFIX}/${TERRAFORM_PROVIDER_DIR}/${TERRAFORM_PROVIDER_BIN} \
		    ${DESTDIR}${PREFIX}/${OPENTOFU_PROVIDER_DIR}/${TERRAFORM_PROVIDER_BIN} ; \
		${RM} -rf ${WRKDIR}/bin ; \
		${RM} -rf ${WRKDIR}/pkg ; \
	fi
.endif
