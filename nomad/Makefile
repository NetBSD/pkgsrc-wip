# $NetBSD$

DISTNAME=	nomad-1.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://www.nomadproject.io/
COMMENT=	Workload orchestrator that can deploy a mix of applications
LICENSE=	mpl-2.0 # actual license is 'unusable for production use', i.e. non-free

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
