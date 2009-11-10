# $NetBSD: Makefile,v 1.4 2009/11/10 08:36:28 thomasklausner Exp $

DISTNAME=	smtpproxy-1.3.3
CATEGORIES=	mail
MASTER_SITES=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/download/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/proxies/00-WikiIndex
COMMENT=	The smtp.proxy is an application level gateway for SMTP
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtp.proxy ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/smtp.proxy.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
