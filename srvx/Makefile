# $NetBSD: Makefile,v 1.3 2003/09/28 03:36:32 virtus Exp $
#

DISTNAME=	srvx-1.1.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=srvx/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://srvx.sourceforge.net/
COMMENT=	Srvx IRC services

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
