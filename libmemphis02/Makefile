# $NetBSD: Makefile,v 1.1 2014/12/25 15:18:45 nros Exp $

DISTNAME=	memphis-0.2.3
PKGNAME=	libmemphis02-0.2.3
CATEGORIES=	geography
MASTER_SITES=	-https://github.com/jiuka/memphis/archive/0.2.3.tar.gz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiuka/mempis
COMMENT=	Library for OpenStreetMap
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config

CONFIGURE_ARGS+=--enable-gtk-doc

PKGCONFIG_OVERRIDE+=memphis.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize --copy; aclocal -I m4; \
	gtkdocize --copy; autoheader; \
	automake -a --foreign -i --add-missing; autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
