# $NetBSD: Makefile,v 1.1.1.1 2005/10/17 14:41:43 ghen Exp $

DISTNAME=	wsbasic-1_2_4
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://wsbasic.sourceforge.net/
COMMENT=	Simple BASIC interpreter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wsbasic ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
