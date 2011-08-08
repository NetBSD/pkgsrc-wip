# $NetBSD: Makefile,v 1.2 2011/08/08 13:00:44 ryo-on Exp $

DISTNAME=	wkhtmltopdf-0.10.0_rc2
CATEGORIES=	textproc
MASTER_SITES=	http://wkhtmltopdf.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://code.google.com/p/wkhtmltopdf/
COMMENT=	Prints a XHTML document into PDF thanks to the webkit engine
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=            yes
USE_LANGUAGES=          c++
USE_TOOLS=		make

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} wkhtmltopdf.pro)

do-install:
	(cd ${WRKSRC} && make INSTALL_ROOT=${DESTDIR}${PREFIX} install)

SUBST_CLASSES+=		target

SUBST_MESSAGE.target=	Fixing target (make install).
SUBST_STAGE.target=	post-build
SUBST_FILES.target=	src/pdf/Makefile src/image/Makefile
SUBST_SED.target=	-e 's,--mode=install cp "$$(QMAKE_TARGET)",--mode=install cp "$$(TARGET)",g'

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
