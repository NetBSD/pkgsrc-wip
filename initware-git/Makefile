# $NetBSD$

DISTNAME=	initware
PKGNAME=	initware-208
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=InitWare/}

GIT_REPOSITORIES=	initware
GIT_REPO.initware=	https://github.com/InitWare/InitWare.git
GIT_BRANCH.initware=	main
WRKSRC=			${WRKDIR}/initware

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://brand.initware.com/
COMMENT=	Services and system resources manager
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
