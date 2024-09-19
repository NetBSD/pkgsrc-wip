# $NetBSD: Makefile,v 1.6 2012/10/05 13:52:03 asau Exp $

DISTNAME=	pop3proxy-2.0.0-beta8
PKGNAME=	${DISTNAME:S/-beta/beta/}
CATEGORIES=	mail
MASTER_SITES=	http://quietsche-entchen.de/download/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/proxies/00-WikiIndex
COMMENT=	The pop3.proxy is an application level proxy for POP3
LICENSE=	gnu-gpl-v2

MAKE_FILE=		makefile
INSTALLATION_DIRS=	sbin man/man1

.include "../../security/clamav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
