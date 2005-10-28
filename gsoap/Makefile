# $NetBSD: Makefile,v 1.4 2005/10/28 21:22:36 mchittur Exp $

DISTNAME=		gsoap_2.7.6c
PKGNAME=		gsoap-2.7.6c
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gsoap2/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://gsoap2.sourceforge.net/
COMMENT=		Tools for coding SOAP XML Web Services in C and C++

WRKSRC=			${WRKDIR}/gsoap-2.7

PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
