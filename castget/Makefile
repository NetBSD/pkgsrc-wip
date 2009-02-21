# $NetBSD: Makefile,v 1.7 2009/02/21 20:49:03 guigui2 Exp $
#

DISTNAME=	castget-1.0.1
PKGREVISION=	1
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/castget/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://castget.nongnu.org/
COMMENT=	Command-line RSS enclosures dowloader

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake intltool pkg-config

AUTO_MKDIRS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/castgetrc.example \
		${PREFIX}/share/examples/castgetrc.example

.include "../../www/curl/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
