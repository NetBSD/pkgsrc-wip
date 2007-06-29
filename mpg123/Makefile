# $NetBSD: Makefile,v 1.1 2007/06/29 02:29:23 bsadewitz Exp $
#

DISTNAME=	mpg123-0.66
CATEGORIES=	local
MASTER_SITES=	http://mpg123.orgis.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://mpg123.orgis.org/download/
COMMENT=        Command-line player for mpeg layer 1, 2 and 3 audio

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	automake

pre-configure:
	cd ${WRKSRC} &&				\
	autoreconf -v --install --force;

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
