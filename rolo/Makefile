# $NetBSD: Makefile,v 1.8 2003/12/29 18:23:51 thomasklausner Exp $

DISTNAME=	rolo-011
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=	bjan+pkgsrc@bjan.net
HOMEPAGE=	http://rolo.sf.net/
COMMENT=	Contact info manager using ncurses and vCards

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rolo
	${INSTALL_DATA} ${WRKSRC}/doc/rfc2426.txt ${PREFIX}/share/doc/rolo

.include "../../devel/ncurses/buildlink2.mk"
.include "../../wip/libvc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
