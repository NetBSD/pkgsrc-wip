# $NetBSD: Makefile,v 1.2 2012/10/03 15:10:00 asau Exp $
#

DISTNAME=	mscore-1.2
PKGNAME=	${DISTNAME:S/mscore/musescore/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mscore/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musescore.org/
COMMENT=	Free cross-platform WYSIWYG music notation program
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
CMAKE_ARGS+=	-DQTDIR:PATH=${QTDIR:Q}
WRKSRC=		${WRKDIR}/${DISTNAME}/mscore
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	all lrelease

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
# musescore links against qt4-tools' libraries
BUILDLINK_DEPMETHOD.qt4-tools= full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
