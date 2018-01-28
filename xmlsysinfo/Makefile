# $NetBSD: Makefile,v 1.5 2012/11/12 16:51:40 othyro Exp $

DISTNAME=	xsi-0.98.29
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlsysinfo/}

MAINTAINER=	haaaad@gmail.com
HOMEPAGE=	http://xsi.kolabore.ath.cx/
COMMENT=	System monitor that provides XML encoded stats


BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.0.0
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0

USE_LANGUAGES+=	c c++

#DEPENDS+=	libxml2>=2.0.0:../../textproc/libxml2
#DEPENDS+=	zlib>=1.2.0:../../devel/zlib

GNU_CONFIGURE=	YES
#USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--enable-user=xsi

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
