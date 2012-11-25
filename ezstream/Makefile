# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:12 othyro Exp $
#

DISTNAME=		ezstream-0.2.0
CATEGORIES=		audio
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://downloads.us.xiph.org/releases/ezstream/
COMMENT=		Streamming client of mp3 and oggvorbis for icecast

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/ezstream
	${INSTALL_DATA} ${WRKSRC:Q}/README ${PREFIX:Q}/share/doc/ezstream/

.include "../../audio/libshout/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
