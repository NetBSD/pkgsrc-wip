# $NetBSD: Makefile,v 1.2 2003/10/06 12:18:46 xtraeme Exp $
#

DISTNAME=		fribidi-0.10.4
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fribidi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://fribidi.sourceforge.net/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

USE_BUILDLINK2=		yes
USE_LIBTOOL=            yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/fribidi.pc.in

TEST_TARGET=		check

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
