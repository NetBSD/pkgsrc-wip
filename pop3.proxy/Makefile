# $NetBSD: Makefile,v 1.1.1.1 2006/03/18 23:02:13 oht Exp $
BETA_TAG=	-beta4

DISTNAME=	pop3proxy-1.3.0
CATEGORIES=	mail
MASTER_SITES=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/download/
EXTRACT_SUFX=   ${BETA_TAG}.tar.gz

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=   	http://quietsche-entchen.de/cgi-bin/wiki.cgi/proxies/00-WikiIndex
COMMENT=	The pop3.proxy is an application level proxy for POP3

MAKEFILE= 	makefile
WRKSRC=		${WRKDIR}/${DISTNAME}${BETA_TAG}

.include "../../mail/clamav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
