# $NetBSD$

DISTNAME=	icestorm-01b9822
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Project IceStorm
LICENSE=	mit

USE_LANGUAGES+=		c c++
USE_TOOLS+= 		pkg-config gmake
LIBS+= 			-lm -lstdc++

GIT_REPOSITORIES=	icestorm
GIT_REPO.icestorm=	git://github.com/cliffordwolf/icestorm.git
GIT_REVISION.icestorm=	01b9822638d60e048c295d005257daa4c147761f
WRKSRC=			${WRKDIR}/icestorm

.include "../../lang/python34/buildlink3.mk"
.include "../../devel/libftdi/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
