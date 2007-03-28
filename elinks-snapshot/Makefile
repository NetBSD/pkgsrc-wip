# $NetBSD: Makefile,v 1.1 2007/03/28 15:30:08 bsadewitz Exp $
#

DISTNAME=	elinks-current-unstable
PKGNAME=	elinks-${ELINKS_VERSION}
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://elinks.or.cz/
COMMENT=	Daily snapshot of the elinks text-mode web browser

CONFLICTS+=	elinks-[0-9]*

CONFIGURE_ARGS+=        --enable-256-colors
CONFIGURE_ENV+=         PKGLOCALEDIR=${PKGLOCALEDIR:Q}

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

BUILD_DEFS+=		LOCALBASE

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

MINOR_VERSION_CMD=      ${DATE} +%Y%m%d
ELINKS_VERSION=		0.12-${ELINKS_MINOR_VERSION:!${MINOR_VERSION_CMD}!}
WRKSRC=			${WRKDIR}/${PKGNAME}


.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
