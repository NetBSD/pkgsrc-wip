# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=	xmltooling-${PKGVERSION}
PKGNAME=	xmltooling-c-${PKGVERSION}
PKGVERSION=	1.2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/latest/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	High level interface for XML processing library
#LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../wip/log4shib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
#.include "../../security/xmlsec1/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
