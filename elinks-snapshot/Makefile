# $NetBSD: Makefile,v 1.8 2012/09/28 22:07:31 asau Exp $
#

DISTNAME=	elinks-current-unstable
PKGNAME=	elinks-snap-${ELINKS_VERSION}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://elinks.or.cz/
COMMENT=	Extended/Enhanced links text-mode web browser (snapshot)

NO_CHECKSUM=	yes

CONFLICTS+=	elinks-[0-9]*

PKG_DESTDIR_SUPPORT=	none

CONFIGURE_ARGS+=	--enable-256-colors --enable-utf-8
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.libiconv:Q}/lib

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake date automake

post-extract:
	cd ${WRKDIR} && ${MV} elinks-* ${DISTNAME}

.include "options.mk"
.include "version.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
