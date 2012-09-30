# $NetBSD: Makefile,v 1.2 2012/09/30 05:44:14 asau Exp $
#

DISTNAME=	i3status-2.3
CATEGORIES=	sysutils wm
MASTER_SITES=	http://i3wm.org/i3status/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://i3wm.org/i3status/
COMMENT=	Small program for generating a status bar
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/i3status
CONF_FILES=	${PREFIX}/share/doc/i3status/i3status.conf ${PKG_SYSCONFDIR}/i3status.conf

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	DEBUG=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3status ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/i3status.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/i3status.conf ${DESTDIR}${PREFIX}/share/doc/i3status/

.include "../../devel/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
