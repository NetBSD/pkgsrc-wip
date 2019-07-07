# $NetBSD$

DISTNAME=	wargus-2.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wargus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/Wargus/wargus
COMMENT=	Importer and scripts for Warcraft2 and Aleonas Tales
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/stormlib/buildlink3.mk"
.include "../../wip/stratagus/buildlink3.mk"
.include "../../wip/tolua++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
