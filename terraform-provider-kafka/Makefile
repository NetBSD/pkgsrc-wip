# $NetBSD$

DISTNAME=	terraform-provider-kafka-0.2.12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mongey/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/Mongey/kafka/
COMMENT=	Terraform provider for managing Apache Kafka Topics and ACLs
LICENSE=	mit

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-kafka
TERRAFORM_PROVIDER_NAMESPACE=	Mongey
TERRAFORM_PROVIDER_TYPE=	kafka

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
