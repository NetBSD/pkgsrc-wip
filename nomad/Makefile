# $NetBSD$

DISTNAME=	nomad-1.0.2
GITHUB_PROJECT=	nomad
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/hashicorp/nomad/
COMMENT=	Workload orchestrator that can deploy a mix of applications
LICENSE=	mpl-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/hashicorp/nomad/


.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
