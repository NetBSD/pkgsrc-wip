# $NetBSD$

DISTNAME=	crush-0.1.8
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=charmbracelet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/charmbracelet/crush/
COMMENT=	Glamourous AI coding agent for your favourite terminal
LICENSE=	fsl-1.1-mit-license

USE_LANGUAGES=	c

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/example

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
