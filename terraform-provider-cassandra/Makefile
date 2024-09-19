# $NetBSD$

DISTNAME=	terraform-provider-cassandra-1.0.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bartoszj/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://registry.terraform.io/providers/bartoszj/cassandra/
COMMENT=	Terraform provider for Apache Cassandra
LICENSE=	mit

GO_BUILD_PATTERN=	.

TERRAFORM_PROVIDER_BIN=		terraform-provider-cassandra
TERRAFORM_PROVIDER_NAMESPACE=	bartoszj
TERRAFORM_PROVIDER_TYPE=	cassandra

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../wip/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
