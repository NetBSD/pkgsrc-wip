# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=	libcli-1.8.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcli/}

MAINTAINER=	haaaad@gmail.com
HOMEPAGE=	http://libcli.sourceforge.net/

COMMENT=	"Provides a shared library for including a Cisco-like CLI."


USE_LANGUAGES+=	c

WRKSRC=			${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS=	lib share/examples

post-extract:
	        ${CHMOD} -R a+r ${WRKSRC}/Doc

post-install:
	        ${CHMOD} ${SHAREMODE} ${PREFIX}/include/libcli.h

.include "../../mk/bsd.pkg.mk"
