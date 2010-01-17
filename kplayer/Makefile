# $NetBSD: Makefile,v 1.10 2010/01/17 12:03:28 thomasklausner Exp $
#

DISTNAME=		kplayer-0.6.3
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kplayer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://kplayer.sourceforge.net/
COMMENT=		KDE media player based on MPlayer
LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake perl
AUTOMAKE_OVERRIDE=	no

pre-configure:
	cd ${WRKSRC} && gmake -f Makefile.dist

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
