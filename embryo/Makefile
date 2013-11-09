# $NetBSD: Makefile,v 1.19 2013/11/09 14:34:47 roelants Exp $
#

DISTNAME=	embryo-1.7.9
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
