# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 03:21:37 poppnk Exp $

DISTNAME=	ldapdns-cvs-snapshot
PKGNAME=	ldapdns-cvs
WRKSRC=		${WRKDIR}/ldapdns/
CATEGORIES=	net
MASTER_SITES=	http://ldapdns.sourceforge.net/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://ldapdns.sourceforge.net
COMMENT=	Tiny, fast authoritative nameserver that queries LDAP

USE_PKGINSTALL=	YES
USE_GMAKE=	YES
ALL_TARGET=	it
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
RCD_SCRIPTS=	ldapdns

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-dg    ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-hosts ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdns-vc    ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/INSTALL       ${PREFIX}/share/doc/ldapdns/
	${INSTALL_DATA}    ${WRKSRC}/README*	   ${PREFIX}/share/doc/ldapdns/

.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
