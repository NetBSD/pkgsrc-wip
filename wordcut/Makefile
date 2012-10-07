# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:07 asau Exp $
#

DISTNAME=	wordcut-0.5.1b2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thaiwordseg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://thaiwordseg.sourceforge.net/
COMMENT=	Thai word segmentation utility
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	wordcut.pc.in

.include "../../mk/bsd.pkg.mk"
