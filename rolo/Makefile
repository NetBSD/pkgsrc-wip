# $NetBSD: Makefile,v 1.2 2003/09/09 04:43:04 bjan2 Exp $

DISTNAME=	rolo-011
CATEGORIES=	databases
MASTER_SITES=	http://osdn.dl.sourceforge.net/sourceforge/rolo/

MAINTAINER=	bjan+pkgsrc@bjan.net
HOMEPAGE=	http://rolo.sf.net/
COMMENT=	Contact info manager using ncurses and vCards

USE_BUILDLINK2=	YES
USE_NCURSES=	YES
GNU_CONFIGURE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rolo
	${INSTALL_DATA} ${WRKSRC}/doc/rfc2426.txt ${PREFIX}/share/doc/rolo

.include "../../devel/ncurses/buildlink2.mk"
.include "../../wip/libvc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
