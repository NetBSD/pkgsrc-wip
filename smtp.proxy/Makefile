# $NetBSD: Makefile,v 1.5 2012/10/07 16:23:15 asau Exp $

DISTNAME=	smtpproxy-1.3.3
CATEGORIES=	mail
MASTER_SITES=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/download/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/proxies/00-WikiIndex
COMMENT=	The smtp.proxy is an application level gateway for SMTP
LICENSE=	gnu-gpl-v2

MAKE_FILE=	makefile

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtp.proxy ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/smtp.proxy.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
