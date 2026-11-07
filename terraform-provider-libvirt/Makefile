# $NetBSD$

DISTNAME=	terraform-provider-libvirt-0.9.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dmacvicar/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/dmacvicar/terraform-provider-libvirt/
COMMENT=	Terraform provider for libvirt
LICENSE=	apache-2.0

TERRAFORM_PROVIDER_BIN=		terraform-provider-libvirt
TERRAFORM_PROVIDER_NAMESPACE=	dmacvicar
TERRAFORM_PROVIDER_TYPE=	libvirt

USE_TOOLS=	gmake pkg-config
USE_LANGUAGES=	c

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake generate

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../net/terraform/provider.mk"
.include "../../mk/bsd.pkg.mk"
