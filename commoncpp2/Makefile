# $NetBSD: Makefile,v 1.1.1.1 2005/04/11 17:12:11 poppnk Exp $
#

DISTNAME=		commoncpp2-1.3.8
CATEGORIES=		wip devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cplusplus/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
