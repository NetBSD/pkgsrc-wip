# $NetBSD: Makefile,v 1.3 2003/12/27 23:09:01 thomasklausner Exp $

DISTNAME=	libvc-003
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rolo/}

MAINTAINER=	bjan+pkgsrc@bjan.net
HOMEPAGE=	http://rolo.sf.net/
COMMENT=	C library for parsing vCard files

GNU_CONFIGURE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

.include "../../mk/bsd.pkg.mk"
