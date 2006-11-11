# $NetBSD: Makefile,v 1.6 2006/11/11 11:31:06 shattered Exp $
#

DISTNAME=		vche-1.7.2
CATEGORIES=		editors
MASTER_SITES=	http://www.grigna.com/diego/linux/vche/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.grigna.com/diego/linux/vche/
COMMENT=		Hex Editor for console

USE_TOOLS+=	gmake

NOT_FOR_PLATFORM=	NetBSD-*-*

do-build:
	cd ${WRKSRC}/src &&\
	gmake -f Rules.make VCHE_NC=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vche-nc ${PREFIX}/bin/vche

.include "../../mk/bsd.pkg.mk"
