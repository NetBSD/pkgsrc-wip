# $NetBSD: Makefile,v 1.1.1.1 2005/02/02 02:33:55 jsrocket Exp $

DISTNAME=	bsflite-0.72
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsflite/}

MAINTAINER=	evan@nixsys.bz
HOMEPAGE=	http://bsflite.sourceforge.net/
COMMENT=	Lightweight AIM client for the command line

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsflite ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
