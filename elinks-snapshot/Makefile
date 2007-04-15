# $NetBSD: Makefile,v 1.3 2007/04/15 00:58:43 bsadewitz Exp $
#

DISTNAME=	elinks-current-unstable
PKGNAME=	elinks-${ELINKS_VERSION}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://elinks.or.cz/
COMMENT=	Extended/Enhanced links text-mode web browser (snapshot)

NO_CHECKSUM=	yes

CONFLICTS+=	elinks-[0-9]*

CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake date

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}


.include "options.mk"
.include "version.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
