# $NetBSD: Makefile,v 1.1 2013/06/18 07:30:54 noud4 Exp $
#

DISTNAME=	libsocialweb-0.25.20
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsocialweb/0.25/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://projects.gnome.org/	# XXX
COMMENT=	Personal social data server
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt
USE_TOOLS+=	gmake
USE_TOOLS+=	perl

PKGCONFIG_OVERRIDE+=	libsocialweb-client.pc.in libsocialweb-keyfob.pc.in \
			libsocialweb-keystore.pc.in libsocialweb-module.pc.in

.include "options.mk"

.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
