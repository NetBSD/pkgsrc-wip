# $NetBSD: Makefile,v 1.15 2013/03/30 07:07:52 shattered Exp $
#

DISTNAME=		kplayer-0.6.3
PKGREVISION=		6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kplayer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
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


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
