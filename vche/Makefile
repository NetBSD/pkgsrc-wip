# $NetBSD: Makefile,v 1.1.1.1 2004/03/14 22:17:17 poppnk Exp $
#

DISTNAME=		vche-1.7.2
CATEGORIES=		wip editors
MASTER_SITES=		http://www.grigna.com/diego/linux/vche/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.grigna.com/diego/linux/vche/
COMMENT=		Hex Editor for console

GNU_TOOLS+=	make
USE_BUILDLINK3=		yes

do-build:
	cd ${WRKSRC}/src &&\
	${GMAKE} -f Rules.make VCHE_NC=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vche-nc ${PREFIX}/bin/vche

.include "../../mk/bsd.pkg.mk"
