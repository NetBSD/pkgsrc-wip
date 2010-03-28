# $NetBSD: Makefile,v 1.1.1.1 2010/03/28 05:13:30 ryo-on Exp $
#

DISTNAME=	quvi-0.1.3
CATEGORIES=	net multimedia www
MASTER_SITES=	http://quvi.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/quvi/
COMMENT=	The quvi is command line tool and library for parsing video download links
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.pcre+=		pcre>=7.8
BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.0
BUILDLINK_API_DEPENDS.libiconv+=	libiconv>=7.18.0

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-smut

PKGCONFIG_OVERRIDE+=	libquvi.pc.in

.include "../../lang/perl5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
