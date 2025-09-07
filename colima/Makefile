# $NetBSD$

DISTNAME=	colima-0.8.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=abiosoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abiosoft/colima/
COMMENT=	Container runtimes on macOS (and Linux) with minimal setup
LICENSE=	mit

DEPENDS+=	lima-[0-9]*:../../wip/lima

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
