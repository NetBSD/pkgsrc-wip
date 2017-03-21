# $NetBSD: Makefile,v 1.12 2014/10/19 22:27:47 alnsn Exp $
#

DISTNAME=	libquvi-0.9.4
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Library for quvi
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	quvi<=0.2.19

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libquvi.pc.in

BUILDLINK_API_DEPENDS.libquvi-scripts+=		libquvi-scripts>=0.9.0
.include "../../wip/libquvi-scripts/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.2
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libiconv+=	libiconv>=1.12.0
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.lua+=		lua>=5.1
.include "../../lang/lua/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=		libgcrypt>=1.4.5
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.24
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
