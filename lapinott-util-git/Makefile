# $NetBSD: Makefile,v 1.18 2018/03/12 11:17:42 wiz Exp $

DISTNAME=	util-0.0
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GITHUB:=lapinott/}
GIT_REPO=       https://github.com/lapinott/util.git
#GITHUB_COMMIT=	2b1e344cdc34874b4ad84147128c94ef4b9b8b68

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lapinott/util
COMMENT=	Utility library for zipfs
LICENSE=	mit

WRKSRC=			${WRKDIR}/${PKGBASE}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
CMAKE_ARGS+=	-DBOOST_DIR=${BUILDLINK_PREFIX.boost-libs}

.include "../../wip/mk/git-package.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
