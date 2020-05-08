# $NetBSD$

GITHUB_PROJECT=	terraform
GITHUB_TAG=	v0.12.24
DISTNAME=	v0.12.24
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://terraform.io/
COMMENT=	Tool for defining infrastructure as code
LICENSE=	mpl-2.0

GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=     github.com/hashicorp/terraform/

INSTALLATION_DIRS+=     bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/terraform ${DESTDIR}${PREFIX}/bin


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
