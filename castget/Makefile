# $NetBSD: Makefile,v 1.8 2009/07/29 09:46:00 jihbed Exp $
#

DISTNAME=	castget-1.0.1
PKGREVISION=	1
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/castget/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://castget.nongnu.org/
COMMENT=	Command-line RSS enclosures dowloader

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake intltool pkg-config

AUTO_MKDIRS=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/castgetrc.example \
		${DESTDIR}${PREFIX}/share/examples/castgetrc.example

.include "../../www/curl/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
