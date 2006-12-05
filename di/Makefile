# $NetBSD: Makefile,v 1.6 2006/12/05 22:54:42 dhowland Exp $

DISTNAME=	di-4.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.gentoo.com/di/
COMMENT=	Command-line disk information utility

MAKE_ENV+=	prefix=${PREFIX:Q}

USE_PKGLOCALEDIR=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/de_DE/LC_MESSAGES
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/en_US/LC_MESSAGES
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/po/de_DE.po \
		${PREFIX}/${PKGLOCALEDIR}/locale/de_DE/LC_MESSAGES/di.po
	${INSTALL_DATA} ${WRKSRC}/po/en_US.po \
		${PREFIX}/${PKGLOCALEDIR}/locale/en_US/LC_MESSAGES/di.po
	${INSTALL_MAN} ${WRKSRC}/di.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/di ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/di ${PREFIX}/bin/mi

.include "../../mk/bsd.pkg.mk"
