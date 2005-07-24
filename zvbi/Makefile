# $NetBSD: Makefile,v 1.1.1.1 2005/07/24 23:43:17 thomasklausner Exp $
#

DISTNAME=		zvbi-0.2.16
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/
COMMENT=		Library for accessing raw VBI sampling devices

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/zvbi-0.2.pc.in
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../textproc/libunicode/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
