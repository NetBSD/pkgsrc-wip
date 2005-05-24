# $NetBSD: Makefile,v 1.4 2005/05/24 10:31:48 rillig Exp $
#

DISTNAME=		vche-1.7.2
CATEGORIES=		wip editors
MASTER_SITES=	http://www.grigna.com/diego/linux/vche/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.grigna.com/diego/linux/vche/
COMMENT=		Hex Editor for console

USE_TOOLS+=	gmake

NOT_FOR_PLATFORM=	NetBSD-*-*

do-build:
	cd ${WRKSRC}/src &&\
	${GMAKE} -f Rules.make VCHE_NC=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vche-nc ${PREFIX}/bin/vche

.include "../../mk/bsd.pkg.mk"
