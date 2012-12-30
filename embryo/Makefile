# $NetBSD: Makefile,v 1.16 2012/12/30 19:43:00 roelants Exp $
#

DISTNAME=	embryo-1.7.4
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Embeddable Scripting Language
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../wip/eina/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
