# $NetBSD: Makefile,v 1.10 2014/04/07 15:01:44 adam Exp $

DISTNAME=	cgic-2.08
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=boutell/}
GITHUB_TAG=	724a845f1b1699dee167d741b9b33cd5ec2310c2
LICENSE=	mit

MAINTAINER=	pkgsrc@ka8zrt.com
HOMEPAGE=	https://github.com/boutell/cgic
COMMENT=	Thomas Boutell's ANSI C library for CGI Programming

INSTALLATION_DIRS=	include lib
USE_LIBTOOL=		yes
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
