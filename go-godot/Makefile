# $NetBSD$

DISTNAME=	godot-1.3.2
PKGNAME=	go-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tetafro/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tetafro/godot/
COMMENT=	Linter that checks if comments end in a period
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/tetafro/godot

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/godot ${DESTDIR}${PREFIX}/bin
	
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
