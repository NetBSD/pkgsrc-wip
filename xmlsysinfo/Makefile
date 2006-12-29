# $NetBSD: Makefile,v 1.1.1.1 2006/12/29 21:48:05 haad Exp $
#

DISTNAME=	xsi-0.98.29
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.sourceforge.net/xmlsysinfo/

MAINTAINER=	haaaad@gmail.com
HOMEPAGE=	http://xsi.kolabore.ath.cx/
COMMENT=	"system monitor that provides XML encoded stats"

MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=xmlsysinfo/}

BUILDLINK_API_DEPENDS.libxml2+=   libxml2>=2.0.0
BUILDLINK_API_DEPENDS.zlib+=	  zlib>=1.2.0

USE_LANGUAGES+=	c c++

#DEPENDS+=	libxml2>=2.0.0:../../textproc/libxml2
#DEPENDS+=      zlib>=1.2.0:../../devel/zlib

GNU_CONFIGURE=          YES
#USE_LIBTOOL=            YES

CONFIGURE_ARGS+= --enable-user=xsi

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
