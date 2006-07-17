# $NetBSD: Makefile,v 1.2 2006/07/17 20:51:42 unex_linija Exp $

DISTNAME=	libsoap-1.1.0
PKGNAME=	csoap-1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=csoap/}

EXTRACT_SUFX=	rc1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://csoap.sourceforge.net/
COMMENT=	SOAP C Framework C API functions

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
