# $NetBSD: Makefile,v 1.1.1.2 2003/05/17 14:29:33 virtus Exp $
#

DISTNAME=	srvx-1.1.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=srvx/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://srvx.sf.net/
COMMENT=	svrx IRC services

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
