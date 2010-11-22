# $NetBSD: Makefile,v 1.1.1.1 2010/11/22 21:41:47 ryo-on Exp $
#

DISTNAME=	qgoogletranslator-1.2.1
CATEGORIES=	editors
MASTER_SITES=	http://qgt.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/qgt/
COMMENT=	Qt gui for google translate based on ajax api
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

USE_LANGUAGES=	c++ c
USE_CMAKE=	yes

FIND_PREFIX:=	MPG123DIR=mpg123

SUBST_CLASSES+=		mpg123-cmd
SUBST_STAGE.mpg123-cmd=	pre-configure
SUBST_FILES.mpg123-cmd=	src/defines.h.in
SUBST_SED.mpg123-cmd=	-e 's,/usr/bin/mpg123,${MPG123DIR}/bin/mpg123,'
SUBST_SED.mpg123-cmd+=	-e 's,/usr/local/bin/mpg123,${MPG123DIR}/bin/mpg123,'

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/find-prefix.mk"
.include "../../mk/bsd.pkg.mk"
