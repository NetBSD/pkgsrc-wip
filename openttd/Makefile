# $NetBSD: Makefile,v 1.8 2010/08/29 10:27:07 ggergely Exp $
#

VERSION=	1.0.3
DISTNAME=	openttd-${VERSION}-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	http://binaries.openttd.org/releases/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix-dir=${PREFIX}
# for now disable lzo. later maybe include as an option...
CONFIGURE_ARGS+=	--without-liblzo2
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/openttd
CONFIGURE_ARGS+=	--man-dir=${PKGMANDIR}/man6
CONFIGURE_ARGS+=	--install-dir=${DESTDIR}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++

.include "options.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
