# $NetBSD$

DISTNAME=	initware
PKGNAME=	initware-git
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=InitWare/}

GIT_REPOSITORIES=	initware
GIT_REPO.initware=	https://github.com/InitWare/InitWare.git
GIT_BRANCH.initware=	main
GIT_REVISION.initware=	6c926fb5106d46b240f79cfdf749a393940017d1
WRKSRC=			${WRKDIR}/initware

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/InitWare/InitWare
COMMENT=	Suite for management of services and system resources
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config sh

RCD_SCRIPTS=	initware

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
