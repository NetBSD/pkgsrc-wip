# $NetBSD: Makefile,v 1.5 2012/10/03 09:06:28 asau Exp $

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
MESSAGE_SUBST+=		PREFIX=${PREFIX}

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	lkm

WRKSRC=			${WRKDIR}/ppp-lzs-1.2

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.lzs-lkm
PKG_SUPPORTED_OPTIONS=	lkm-diagnostic lkm-debug lkm-lockdebug lkm-malloclog lkm-multiprocessor

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlkm-diagnostic)
CPPFLAGS+=		-DDIAGNOSTIC
.endif

.if !empty(PKG_OPTIONS:Mlkm-debug)
CPPFLAGS+=		-DDEBUG
.endif

.if !empty(PKG_OPTIONS:Mlkm-lockdebug)
CPPFLAGS+=		-DLOCKDEBUG
.endif

.if !empty(PKG_OPTIONS:Mlkm-malloclog)
CPPFLAGS+=		-DMALLOCLOG
.endif

.if !empty(PKG_OPTIONS:Mlkm-multiprocessor)
CPPFLAGS+=		-DMULTIPROCESSOR
.endif

INSTALLATION_DIRS=	lkm

do-install:
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKSRC}/lkm/lzs.o ${DESTDIR}${PREFIX}/lkm/lzs.o

.include "../../mk/bsd.pkg.mk"
