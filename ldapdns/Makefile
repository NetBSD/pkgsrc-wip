# $NetBSD: Makefile,v 1.4 2004/05/09 06:56:20 blef Exp $

DISTNAME=	ldapdns-cvs-snapshot
PKGNAME=	ldapdns-cvs-0.0.1
WRKSRC=		${WRKDIR}/ldapdns/
CATEGORIES=	net
MASTER_SITES=	http://ldapdns.sourceforge.net/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://ldapdns.sourceforge.net
COMMENT=	Tiny, fast authoritative nameserver that queries LDAP

USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	it
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
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
