# $NetBSD: Makefile,v 1.3 2005/07/29 08:32:46 ianzag Exp $
#

DISTNAME=		commoncpp2-1.3.16
CATEGORIES=		wip devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnutelephony/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
