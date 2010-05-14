# $NetBSD: Makefile,v 1.1.1.1 2010/05/14 11:06:38 obache Exp $
#

DISTNAME=	kimera-2.11
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=kimera/37271/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://kimera.sourceforge.jp/
COMMENT=	Kanji Input MEthod for RAgamuffins
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake \
		target.path=${PREFIX}/share/kimera \
		script.path=${PREFIX}/bin \
		kimera.pro

.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
