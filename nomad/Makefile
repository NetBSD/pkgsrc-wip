# $NetBSD$

GITHUB_PROJECT=	nomad
GITHUB_TAG=	v0.11.1
DISTNAME=	v0.11.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/hashicorp/nomad/
COMMENT=	Workload orchestrator that can deploy a mix of applications
LICENSE=	mpl-2.0

GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=     github.com/hashicorp/nomad/

INSTALLATION_DIRS+=     bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/nomad ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
