# $NetBSD$

DISTNAME=	wyrmsun-5.3.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Andrettin/}
GITHUB_PROJECT=	Wyrmsun
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://andrettin.github.io/
COMMENT=	Strategy game with elements of mythology, history and fiction
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes

DEPENDS+=	wyrmgus>=5.3.5:../../wip/wyrmgus

.include "../../mk/bsd.pkg.mk"
