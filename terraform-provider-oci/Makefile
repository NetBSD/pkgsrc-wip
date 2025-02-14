# $NetBSD$

DISTNAME=	terraform-provider-oci-6.26.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=oracle/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oracle/terraform-provider-oci/
COMMENT=	Terraform provider for Oracle Cloud Infrastructure
LICENSE=	mpl-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-oci
TERRAFORM_PROVIDER_NAMESPACE=	oracle
TERRAFORM_PROVIDER_TYPE=	oci

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
