# $NetBSD: Makefile,v 1.7 2005/06/25 23:28:35 ishit Exp $

DISTNAME=		WEPCrack-0.1.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wepcrack/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wepcrack.sourceforge.net/
COMMENT=		Open source tool for breaking 802.11 WEP secret keys

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	perl

do-install:
	for A in ${WRKSRC}/*.pl; do \
	${MV} $${A} $${A}.orig; \
	${SED} 's@#!/usr/bin/perl@#!${PREFIX}/bin/perl@' < $${A}.orig > $${A}; \
	${INSTALL_SCRIPT} $${A} ${LOCALBASE}/bin; \
	done

.include	"../../mk/bsd.pkg.mk"
