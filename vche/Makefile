# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:10 tvierling Exp $
#

DISTNAME=		vche-1.7.2
CATEGORIES=		wip editors
MASTER_SITES=	http://www.grigna.com/diego/linux/vche/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.grigna.com/diego/linux/vche/
COMMENT=		Hex Editor for console

USE_GNU_TOOLS+=	make

NOT_FOR_PLATFORM=	NetBSD-*-*

do-build:
	cd ${WRKSRC}/src &&\
	${GMAKE} -f Rules.make VCHE_NC=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vche-nc ${PREFIX}/bin/vche

.include "../../mk/bsd.pkg.mk"
