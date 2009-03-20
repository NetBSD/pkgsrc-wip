# $NetBSD: Makefile,v 1.4 2009/03/20 22:49:03 jihbed Exp $

DISTNAME=	libsoap-1.1.0
PKGNAME=	csoap-1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=csoap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://csoap.sourceforge.net/
COMMENT=	SOAP C Framework C API functions

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config



.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
