# $NetBSD: Makefile,v 1.1.1.1 2010/05/14 11:11:02 obache Exp $
#

DISTNAME=	wordcut-0.5.1b2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=thaiwordseg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://thaiwordseg.sourceforge.net/
COMMENT=	Thai word segmentation utility
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	wordcut.pc.in

.include "../../mk/bsd.pkg.mk"
