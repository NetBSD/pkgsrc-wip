# $NetBSD: Makefile,v 1.1.1.1 2011/05/12 05:19:58 makoto Exp $

DISTNAME=	anthy-dic-jis34-0.2
CATEGORIES=	inputmethod
MASTER_SITES=	http://yanok.net/dist/anthy-dic-jis34/

MAINTAINER=	package-users@jp.NetBSD.org
HOMEPAGE=	http://yanok.net/dist/anthy-dic-jis34/
COMMENT=	Dictionary of JIS level 3 and 4 for Anthy
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	ANTHYDIC_DIR

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

ANTHYDIC_DIR=	${PREFIX}/share/${PKGBASE}
INSTALLATION_DIRS=	share/${PKGBASE}
AUTO_MKDIRS=	YES

INSTALL_FILES=	README COPYING jis3_4.t ChangeLog

DEPENDS+=	anthy:../../inputmethod/anthy

do-install:
.for file in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${ANTHYDIC_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
