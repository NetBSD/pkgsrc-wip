# $NetBSD: Makefile,v 1.7 2012/09/28 21:00:33 asau Exp $

DISTNAME=	di-4.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.gentoo.com/di/
COMMENT=	Command-line disk information utility

MAKE_ENV+=	prefix=${PREFIX:Q}

USE_PKGLOCALEDIR=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/de_DE/LC_MESSAGES
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/en_US/LC_MESSAGES
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/po/de_DE.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/de_DE/LC_MESSAGES/di.po
	${INSTALL_DATA} ${WRKSRC}/po/en_US.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/en_US/LC_MESSAGES/di.po
	${INSTALL_MAN} ${WRKSRC}/di.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/di ${DESTDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/di ${DESTDIR}${PREFIX}/bin/mi

.include "../../mk/bsd.pkg.mk"
