# $NetBSD: Makefile,v 1.13 2010/12/12 20:56:15 ryo-on Exp $
#

DISTNAME=	quvi-0.2.10
CATEGORIES=	net multimedia www
MASTER_SITES=	http://quvi.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/quvi/
COMMENT=	The quvi is command line tool and library for parsing video links
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_VARS+=	doc

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-nsfw

PKGCONFIG_OVERRIDE+=	libquvi.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.pcre+=		pcre>=7.8
.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.0
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libiconv+=	libiconv>=1.12.0
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.lua+=		lua>=5.1
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
