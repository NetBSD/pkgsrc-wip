# $NetBSD: Makefile,v 1.5 2006/05/16 05:26:25 martijnb Exp $
#

DISTNAME=		nzbget-0.2.3
PKGREVISION=		2
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nzbget/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://www.sourceforge.net/projects/nzbget/
COMMENT=		Binary newsreader with NZB support

USE_TOOLS+=	        gmake
USE_TOOLS+=		autoconf
USE_LANGUAGES+=		c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

EGDIR=          	${PREFIX}/share/examples/nzbget
MESSAGE_SUBST+=		EGDIR=${EGDIR}

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/nzbget.cfg.example \
		${EGDIR}/nzbget.cfg.example

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
