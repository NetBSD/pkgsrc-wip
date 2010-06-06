# $NetBSD: Makefile,v 1.3 2010/06/06 10:34:51 jihbed Exp $
#

DISTNAME=	openbabel-2.2.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openbabel/}

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://openbabel.sourceforge.net/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	openbabel-2.0.pc.in

CONFIGURE_ARGS+=	--disable-inchi
CONFIGURE_ARGS+=	--disable-dynamic-modules
CONFIGURE_ARGS+=	--disable-inchi

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
