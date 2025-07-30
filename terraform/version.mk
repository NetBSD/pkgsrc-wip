# $NetBSD$

OPENTOFU_VERSION=	1.10.3
TERRAFORM13_VERSION=	1.3.8
TERRAFORM11_VERSION=	1.1.9
TERRAFORM015_VERSION=	0.15.1
TERRAFORM014_VERSION=	0.14.11
#TERRAFORM013_VERSION=	TODO
#TERRAFORM012_VERSION=	TODO

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

TERRAFORM_VERSION_DEFAULT?=	015

# FIXME: This is used in `do-install:' target and should be fixed in order to be
# FIXME: able to install different terraform version without adjusting
# FIXME: TERRAFORM_VERSION_DEFAULT. In some way we need a mapping between
# FIXME: TERRAFORM_VERSION and TERRAFORMVERSSUFFIX.
.if !empty(TERRAFORM_VERSION_DEFAULT)
TERRAFORMVERSSUFFIX=		${TERRAFORM_VERSION_DEFAULT}
.endif

# Preferred version dependency for Terraform
# FIXME: this should be instructed to handle OpenTofu
TERRAFORM_PACKAGE_DEP=		terraform${TERRAFORMVERSSUFFIX}-${TERRAFORM${TERRAFORMVERSSUFFIX}_VERSION}*:../../wip/terraform${TERRAFORMVERSSUFFIX}

PLIST_SUBST+=	TERRAFORMVERSSUFFIX=${TERRAFORMVERSSUFFIX:Q}

PRINT_PLIST_AWK+=	{ sub("${TERRAFORMVERSSUFFIX}", "$${TERRAFORMVERSSUFFIX}") }
