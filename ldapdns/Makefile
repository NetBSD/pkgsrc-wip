# $NetBSD: Makefile,v 1.9 2012/10/01 22:20:17 asau Exp $

DISTNAME=	ldapdns-cvs-snapshot
PKGNAME=	ldapdns-cvs-0.0.1
WRKSRC=		${WRKDIR}/ldapdns/
CATEGORIES=	net
MASTER_SITES=	http://ldapdns.sourceforge.net/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://ldapdns.sourceforge.net
COMMENT=	Tiny, fast authoritative nameserver that queries LDAP

USE_TOOLS+=	gmake
BUILD_TARGET=	it
GNU_CONFIGURE=	YES
RCD_SCRIPTS=	ldapdns

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-dg    ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-hosts ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-vc    ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/INSTALL       ${DESTDIR}${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/README*	   ${DESTDIR}${PREFIX}/share/doc/ldapdns/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
