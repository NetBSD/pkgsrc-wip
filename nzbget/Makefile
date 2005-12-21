# $NetBSD: Makefile,v 1.1 2005/12/21 10:28:27 martijnb Exp $
#

DISTNAME=		nzbget-0.2.3
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nzbget/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://www.sourceforge.net/projects/nzbget/
COMMENT=		Binary newsreader with NZB support

USE_TOOLS+=	        gmake
USE_TOOLS+=		autoconf
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

EGDIR=          	${LOCALBASE}/share/examples/nzbget

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/nzbget.cfg.example \
		${EGDIR}/nzbget.cfg.example

.include "../../mk/curses.buildlink3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
