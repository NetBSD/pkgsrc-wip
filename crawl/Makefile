# $NetBSD: Makefile,v 1.1.1.1 2004/06/12 11:02:52 ppostma Exp $

DISTNAME=	crawl-0.4
CATEGORIES=	www
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://monkey.org/~provos/crawl/
COMMENT=	Small and efficient HTTP crawler

GNU_CONFIGURE=	yes
USE_PKGINSTALL=	yes
USE_BUILDLINK3=	yes
USE_DB185=	yes

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/crawl.conf ${PKG_SYSCONFDIR}/crawl.conf

post-patch:
	@${MV} ${WRKSRC}/cfg.h ${WRKSRC}/cfg.h.orig
	@${SED} -e 's!@@PREFIX@@!${PREFIX}!g' < ${WRKSRC}/cfg.h.orig > \
	   ${WRKSRC}/cfg.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/crawl.conf ${PREFIX}/share/examples/${PKGBASE}/crawl.conf

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
