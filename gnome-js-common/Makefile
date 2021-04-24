# $NetBSD: Makefile,v 1.3 2013/06/19 13:15:52 noud4 Exp $

DISTNAME=	gnome-js-common-0.1.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-js-common/0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
#HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/gnome-js-common/0.1/
COMMENT=	GNOME JavaScript common modules and tests
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt

PKGCONFIG_OVERRIDE+=	gnome-js-common.pc.in

CONFIGURE_ARGS+=	--enable-seed
CONFIGURE_ARGS+=	--enable-gjs

.include "../../mk/bsd.pkg.mk"
