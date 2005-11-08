# $NetBSD: Makefile,v 1.1.1.1 2005/11/08 20:31:31 poppnk Exp $
#

DISTNAME=		ezstream-0.2.0
CATEGORIES=		/usr/pkgsrc/wip/ezstream
MASTER_SITES=		http://downloads.us.xiph.org/releases/ezstream/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://downloads.us.xiph.org/releases/ezstream/
COMMENT=		Streamming client of mp3 and oggvorbis for icecast

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ezstream
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ezstream/

.include "../../audio/libshout/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
