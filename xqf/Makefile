# $NetBSD$

GITHUB_PROJECT=	pkgsrc
DISTNAME=	xqf-1.0.7.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=shozp/}
GITHUB_RELEASE=	pkgsrc-xqf
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=     shozp@directbox.com
HOMEPAGE=       https://github.com/XQF/xqf/
COMMENT=        XQF is a server browser and launcher for games
LICENSE=        gnu-gpl-v2

DEPENDS+=       gtk2-[0-9]*:../../x11/gtk2
DEPENDS+=       qstat-[0-9]*:../../wip/qstat
DEPENDS+=	minizip-[0-9]*:../../archivers/minizip
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+	GeoIP-[0-9]*:../../net/GeoIP

WRKSRC=			${WRKDIR}/xqf-master
USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=          c c++

.include "../../x11/gtk2/buildlink3.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
