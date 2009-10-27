# $NetBSD: Makefile,v 1.1 2009/10/27 11:29:57 pettai Exp $
#

DISTNAME=	opensaml-2.2.1
PKGNAME=	opensaml2-2.2.1
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/latest/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opensaml.org/
COMMENT=	Security Assertion Markup Language (SAML)
#LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/log4shib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
#.include "../../security/xmlsec1/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../wip/xmltooling-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
