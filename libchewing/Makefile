# $NetBSD: Makefile,v 1.1.1.1 2009/01/14 13:41:27 obache Exp $
#

DISTNAME=	libchewing-0.3.2
CATEGORIES=	chinese inputmethod
MASTER_SITES=	http://chewing.csie.net/download/libchewing/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://chewing.csie.net/
COMMENT=	The intelligent phonetic input method library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

.include "../../mk/bsd.pkg.mk"
