# $NetBSD: Makefile,v 1.1.1.1 2003/04/25 20:21:43 virtus Exp $
#

DISTNAME=	srvx-1.2rc3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/srvx/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://svrx.sf.net
COMMENT=	svrx IRC services

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
