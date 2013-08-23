# $NetBSD: Makefile,v 1.1 2013/08/23 20:54:49 wongk Exp $

DISTNAME=	yenc-${DISTVERSION}
DISTVERSION= 0.3
DISTFILES=	${DISTNAME}-w32fixed${EXTRACT_SUFX}

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
REPLACE_PYTHON= *.py
CATEGORIES=	news
MASTER_SITES=    ${MASTER_SITE_SOURCEFORGE:=sabnzbdplus/sabnzbdplus-tools/}
EXTRACT_SUFX=	.zip

PYDISTUTILSPKG=         yes


MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://sabnzbdplus.sourceforge.net/
COMMENT=	Python module for yenc decoding module in C
LICENSE=        gnu-gpl-v2

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
