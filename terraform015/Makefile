# $NetBSD$

.include "../../wip/terraform/version.mk"

DISTNAME=	terraform-${TERRAFORM015_VERSION}
PKGNAME=	terraform015-${TERRAFORM015_VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	terraform
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.terraform.io/
COMMENT=	Infrastructure orchestration tool
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	.

SUBST_CLASSES+=			providers-prefix
SUBST_STAGE.providers-prefix=	pre-configure
SUBST_MESSAGE.providers-prefix=	Honor providers installed via pkgsrc
SUBST_FILES.providers-prefix=	provider_source.go
SUBST_VARS.providers-prefix=	PREFIX

CHECK_RELRO_SKIP+=	bin/terraform

WRKSRC=	${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/terraform ${DESTDIR}${PREFIX}/bin/terraform015

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
