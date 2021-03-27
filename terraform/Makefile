# $NetBSD$

DISTNAME=	# empty
PKGNAME=	terraform-${TERRAFORM${TERRAFORMVERSSUFFIX}_VERSION}
CATEGORIES=	net
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/
COMMENT=	Meta package providing preferred version of Terraform
LICENSE=	mpl-2.0

META_PACKAGE=	yes

DEPENDS+=	${TERRAFORM_PACKAGE_DEP}

.include "../../wip/terraform/version.mk"
.include "../../mk/bsd.pkg.mk"
