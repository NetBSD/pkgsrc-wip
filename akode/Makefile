# $NetBSD: Makefile,v 1.1.1.1 2008/12/04 04:31:00 htepper Exp $
#

DISTNAME=		30375-akode-2.0.2
PKGNAME=		akode-2.0.2
CATEGORIES=		audio
MASTER_SITES=		http://www.kde-apps.org/CONTENT/content-files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hasso@NetBSD.org
HOMEPAGE=		http://carewolf.com/akode/
COMMENT=		Simple audio decoding framework

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

SHLIBTOOL_OVERRIDE=	# empty

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
