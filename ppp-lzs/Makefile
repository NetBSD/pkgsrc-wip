# $NetBSD: Makefile,v 1.7 2004/06/12 07:38:39 plunky Exp $

DISTNAME=	ppp-lzs-1.0
PKGNAME=	ppp-lzs-2.4.0
CATEGORIES=	net
MASTER_SITES=	http://homepages.rya-online.net/plunky/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://homepages.rya-online.net/plunky/lzs.html
COMMENT=	PPP daemon and LKM with Stac LZS decompression

CONFLICTS+=		ppp-* ppp-mppe-*
ONLY_FOR_PLATFORM= 	NetBSD-*-*

MAKE_ENV+=	BSDSRCDIR="${BSDSRCDIR}"
MESSAGE_SUBST+= PREFIX="${PREFIX}"
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

pre-patch:
.if !exists(${BSDSRCDIR}/usr.sbin/pppd/Makefile)
	@${ECHO} "This package requires the NetBSD source sets to be installed"
	@${ECHO} "in order to compile, as it patches against the supplied pppd."
	@${ECHO} "Please place them in ${BSDSRCDIR} or set the BSDSRCDIR variable"
	@${ECHO} "to their location."
	@${FALSE}
.endif
	@${MKDIR} ${WRKDIR}/lkm ${WRKDIR}/net ${WRKDIR}/pppd
	@${CP} ${BSDSRCDIR}/sys/net/ppp-comp.h ${WRKDIR}/net/ppp-comp.h
	@${CP} -R ${BSDSRCDIR}/usr.sbin/pppd/pppd ${WRKDIR}

pre-install:
.if !exists(${PREFIX}/lkm)
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lkm
.endif

do-install:
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 4555 \
		${WRKDIR}/pppd/pppd ${PREFIX}/sbin/pppd
	${INSTALL_MAN} ${WRKDIR}/pppd/pppd.cat8 ${PREFIX}/man/cat8/pppd.0
	${INSTALL_MAN} ${WRKDIR}/pppd/pppd.8 ${PREFIX}/man/man8/pppd.8
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WRKDIR}/lkm/lzs.o ${PREFIX}/lkm/lzs.o

.include "../../mk/bsd.pkg.mk"
