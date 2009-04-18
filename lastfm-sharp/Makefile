# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 00:29:20 jihbed Exp $
#

DISTNAME=	liblastfm-sharp-0.1.09
CATEGORIES=	audio
MASTER_SITES=	http://lastfm-sharp.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://lastfm-sharp.googlecode.com/files/
COMMENT=	 .net/mono interface to last.fm

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	src/liblastfm-sharp.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
