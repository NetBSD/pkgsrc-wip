# $NetBSD: Makefile,v 1.1.1.2 2005/02/02 03:58:10 jsrocket Exp $

DISTNAME=	bsflite-0.72
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bsflite/}

MAINTAINER=	leitec@leitec.org
HOMEPAGE=	http://bsflite.sourceforge.net/
COMMENT=	Lightweight AIM client for the command line

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsflite ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
