# $NetBSD: Makefile,v 1.1.1.1 2011/03/05 22:13:33 amoibos Exp $

DISTNAME=	dhex_0.65
PKGNAME=	dhex-0.65
CATEGORIES=	editors
MASTER_SITES=	http://dettus.net/dhex/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://www.dettus.net/dhex/
COMMENT=	The ncurses-based hex-editor with diff mode
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

PKG_DESTDIR_SUPPORT=	user-destdir

MAN1=		dhex.1
MAN5=		dhexrc.5 dhex_markers.5 dhex_searchlog.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/${PKGMANDIR}/man1
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/${PKGMANDIR}/man5
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
