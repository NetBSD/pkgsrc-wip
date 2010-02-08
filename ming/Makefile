# $NetBSD: Makefile,v 1.10 2010/02/08 05:22:45 obache Exp $
#

DISTNAME=	ming-0.4.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ming/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.libming.org/
COMMENT=	SWF output library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bison flex
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-tcl

PKGCONFIG_OVERRIDE+=	src/libming.pc.in

# Test require perl
USE_TOOLS+=	perl
TEST_TARGET=	check

# XXX: "man" is not in SUBDIRS of "docs"
INSTALL_DIRS=	. docs/man

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
