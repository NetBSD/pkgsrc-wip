# $NetBSD: Makefile,v 1.13 2013/11/09 14:28:53 roelants Exp $
#

DISTNAME=	eina-1.7.9
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Core data structure library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	eina.pc.in

.include "../../mk/compiler.mk"

.if empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-mt
.endif

.include "../../mk/bsd.pkg.mk"
