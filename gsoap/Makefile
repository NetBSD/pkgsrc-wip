# $NetBSD: Makefile,v 1.1.1.1 2005/02/19 15:15:19 chriswareham Exp $

DISTNAME=		gsoap-2.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gsoap2/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://gsoap2.sourceforge.net/
COMMENT=		Tools for coding SOAP XML Web Services in C and C++

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
