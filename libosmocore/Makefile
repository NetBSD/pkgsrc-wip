# $NetBSD: Makefile,v 1.4 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=	libosmocore-0.1.30
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	devel
MASTER_SITES=	http://openbsc.osmocom.org/trac/raw-attachment/wiki/Tarballs/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.osmocom.org/
COMMENT=	libosmocore

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	libosmocodec.pc.in
PKGCONFIG_OVERRIDE+=	libosmocore.pc.in
PKGCONFIG_OVERRIDE+=	libosmocovty.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
