# $NetBSD$

DISTNAME=	go-procfs-0.3.0
GITHUB_PROJECT=	procfs
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/prometheus/procfs/
COMMENT=	Procfs provides functions to /proc and /sys
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/prometheus/procfs

USE_TOOLS+=             bash:run

REPLACE_BASH+=	ttar

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix+=	ttar
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_SED.prefix+=	-e 's,/usr/bin/env python,${PREFIX}/bin/python${PYVERSSUFFIX},g'
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../devel/go-sync/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
