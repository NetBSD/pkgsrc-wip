# $NetBSD: Makefile,v 1.2 2006/02/13 20:38:13 plunky Exp $

DISTNAME=		lzs-lkm-1.2
CATEGORIES=		net
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		ppp-lzs-1.2.tar.gz

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://homepages.rya-online.net/plunky/lzs.html
COMMENT=		NetBSD kernel module for LZS decompression with PPP

# TODO - verify version (nbsomething most likely)
DEPENDS+=		pppd>=2.4.3:../../net/pppd

ONLY_FOR_PLATFORM=	NetBSD-*-*
MESSAGE_SUBST+=		PREFIX=${PREFIX:Q}

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	lkm

WRKSRC=			${WRKDIR:Q}/ppp-lzs-1.2

do-install:
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKSRC:Q}/lkm/lzs.o ${PREFIX:Q}/lkm/lzs.o

.include "../../mk/bsd.pkg.mk"
