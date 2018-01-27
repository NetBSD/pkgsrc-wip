# $NetBSD: Makefile,v 1.5 2015/06/07 14:24:49 yrmt Exp $

DISTNAME=	libsocialweb-0.25.20
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsocialweb/0.25/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://projects.gnome.org/	# XXX
COMMENT=	Personal social data server
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool msgfmt
USE_TOOLS+=		gmake
USE_TOOLS+=		perl
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libsocialweb-client.pc.in libsocialweb-keyfob.pc.in \
			libsocialweb-keystore.pc.in libsocialweb-module.pc.in

.include "options.mk"

.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
