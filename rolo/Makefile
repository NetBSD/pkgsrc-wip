# $NetBSD: Makefile,v 1.4 2003/12/25 00:26:39 bjan2 Exp $

DISTNAME=	rolo-011
CATEGORIES=	databases
MASTER_SITES=	http://osdn.dl.sourceforge.net/sourceforge/rolo/

MAINTAINER=	bjan+pkgsrc@bjan.net
HOMEPAGE=	http://rolo.sf.net/
COMMENT=	Contact info manager using ncurses and vCards

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
