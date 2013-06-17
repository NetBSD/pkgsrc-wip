# $NetBSD: Makefile,v 1.7 2013/06/17 12:45:12 thomasklausner Exp $
#

DISTNAME=	liblastfm-sharp-0.1.09
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://lastfm-sharp.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/lastfm-sharp/
COMMENT=	DotNet/Mono interface to last.fm
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	src/liblastfm-sharp.pc.in

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
