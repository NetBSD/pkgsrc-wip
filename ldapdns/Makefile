# $NetBSD: Makefile,v 1.7 2005/05/24 10:30:31 rillig Exp $

DISTNAME=	ldapdns-cvs-snapshot
PKGNAME=	ldapdns-cvs-0.0.1
WRKSRC=		${WRKDIR}/ldapdns/
CATEGORIES=	net
MASTER_SITES=	http://ldapdns.sourceforge.net/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://ldapdns.sourceforge.net
COMMENT=	Tiny, fast authoritative nameserver that queries LDAP

USE_PKGINSTALL=	YES
USE_TOOLS+=	gmake
BUILD_TARGET=	it
GNU_CONFIGURE=	YES
RCD_SCRIPTS=	ldapdns

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-dg    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-hosts ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-vc    ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/INSTALL       ${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/README*	   ${PREFIX}/share/doc/ldapdns/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
