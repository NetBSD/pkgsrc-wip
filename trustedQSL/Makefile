# $NetBSD: Makefile,v 1.1 2012/10/02 15:25:35 makoto Exp $

DISTNAME=	TrustedQSL-1_13
PKGNAME=	TrustedQSL-1.13
CATEGORIES=     ham
MASTER_SITES=	http://www.arrl.org/files/file/LoTW%20Instructions/
#LICENSE=	arrl

EXTRACT_SUFX=	_tar.gz

MAINTAINER=     makoto@ki.nu
HOMEPAGE=       http://www.arrl.org/files/file/LoTW%20Instructions/
COMMENT=        Uploading QSL Data to LoTW of ARRL
WRKSRC=         ${WRKDIR}/${PKGNAME}

USE_TOOLS+=	perl gmake
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=--with-tqsllib=${PREFIX}/lib
# looking for bin/wx-config under it.
CONFIGURE_ARGS+=--with-wxwindows=${PREFIX}

SUBST_CLASSES+=         wxwindows
SUBST_STAGE.wxwindows=    post-patch
SUBST_FILES.wxwindows=    configure
SUBST_MESSAGE.wxwindows=  Adjust wxWindows path
SUBST_SED.wxwindows=      -e s\|@@PREFIX@@\|${PREFIX}\|


.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../wip/tqsllib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
