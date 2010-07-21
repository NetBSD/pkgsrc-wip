# $NetBSD: Makefile,v 1.3 2010/07/21 11:04:53 ryo-on Exp $
#

DISTNAME=	quvi-0.2.0
CATEGORIES=	net multimedia www
MASTER_SITES=	http://quvi.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/quvi/
COMMENT=	The quvi is command line tool and library for parsing video links
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.0
BUILDLINK_API_DEPENDS.pcre+=		pcre>=7.8
BUILDLINK_API_DEPENDS.libiconv+=	libiconv>=1.12.0
BUILDLINK_API_DEPENDS.lua+=		lua>=5.1

PLIST_VARS+=	doc

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-smut

PKGCONFIG_OVERRIDE+=	libquvi.pc.in

.include "options.mk"

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
