# $NetBSD: Makefile,v 1.2 2007/09/24 19:10:53 guigui2 Exp $
#

DISTNAME=	castget-1.0.0
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/castget/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://savannah.nongnu.org/download/castget/
COMMENT=	Command-line RSS enclosures dowloader

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=             gmake intltool pkg-config

EGDIR+=		${PREFIX}/share/examples/castget

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/castgetrc.example ${EGDIR}/castgetrc.example

.include "../../www/curl/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
