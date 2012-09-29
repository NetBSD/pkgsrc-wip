# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:35 asau Exp $
#

DISTNAME=	glyr-1.0.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/downloads/sahib/glyr/
EXTRACT_SUFX=	.tar.bz2
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahib/glyr/
COMMENT=	Music related metadata search engine with CLI and C API
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/glyr
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	glyr/libglyr.pc.in

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../wip/libexecinfo/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
