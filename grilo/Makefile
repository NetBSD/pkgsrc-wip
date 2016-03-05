# $NetBSD: Makefile,v 1.17 2015/10/10 01:57:53 ryoon Exp $
#

DISTNAME=	grilo-0.3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/grilo/0.3/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Media browser framework
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt
USE_LANGUAGES=	c99
SET_LIBDIR=	yes

CONFIGURE_ARGS+=	"--enable-grl-pls"

PKGCONFIG_OVERRIDE+=	grilo-0.3.pc.in
PKGCONFIG_OVERRIDE+=	grilo-net-0.3.pc.in
PKGCONFIG_OVERRIDE+=	grilo-pls-0.3.pc.in

.include "../../wip/totem-pl-parser/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
