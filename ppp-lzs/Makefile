# $NetBSD: Makefile,v 1.3 2004/05/09 19:07:36 plunky Exp $

DISTNAME=	ppp-lzs-1.0
CATEGORIES=	net
MASTER_SITES=	http://homepages.rya-online.net/plunky/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://homepages.rya-online.net/plunky/lzs.html
COMMENT=	PPP daemon and LKM with Stac LZS decompression

CONFLICTS+=		ppp-mppe-*
ONLY_FOR_PLATFORM= 	NetBSD-*-*

MAKE_ENV+=	BSDSRCDIR="${BSDSRCDIR}"
MESSAGE_SUBST+= PREFIX="${PREFIX}"
WRKSRC=		${WRKDIR}

pre-patch:
	@${MKDIR} ${WRKDIR}/lkm ${WRKDIR}/net ${WRKDIR}/pppd
	@${CP} ${BSDSRCDIR}/sys/net/ppp-comp.h ${WRKDIR}/net/ppp-comp.h
	@${CP} ${BSDSRCDIR}/usr.sbin/pppd/pppd/Makefile ${WRKDIR}/pppd/Makefile
	@${CP} ${BSDSRCDIR}/usr.sbin/pppd/pppd/ccp.c ${WRKDIR}/pppd/ccp.c
	@${CP} ${BSDSRCDIR}/usr.sbin/pppd/pppd/ccp.h ${WRKDIR}/pppd/ccp.h
	@${CP} ${BSDSRCDIR}/usr.sbin/pppd/pppd/pppd.8 ${WRKDIR}/pppd/pppd.8

pre-install:
.if !exists(${PREFIX}/lkm)
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lkm
.endif

do-install:
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 4555 \
		${WRKDIR}/pppd/pppd ${PREFIX}/sbin/pppd
	${INSTALL_MAN} ${WRKDIR}/pppd/pppd.cat8 ${PREFIX}/man/cat8/pppd.0
	${INSTALL_MAN} ${WRKDIR}/pppd/pppd.8 ${PREFIX}/man/man8/pppd.8
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKDIR}/lkm/lzs.o ${PREFIX}/lkm/lzs.o

.include "../../mk/bsd.pkg.mk"
