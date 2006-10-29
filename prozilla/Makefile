# $NetBSD: Makefile,v 1.9 2006/10/29 08:32:53 shattered Exp $
#

DISTNAME=		prozilla-1.3.6
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=		low@ameba6.com
HOMEPAGE=		http://directory.fsf.org/network/Tools/ProZilla.html
COMMENT=		ProZilla is a multi-threaded download accelerator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/prozilla
CONF_FILES=		${EGDIR}/prozilla.conf ${PKG_SYSCONFDIR}/prozilla.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/prozrc.sample ${EGDIR}/prozilla.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
