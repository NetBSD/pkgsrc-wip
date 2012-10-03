# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:40 asau Exp $
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

.include "../../mk/bsd.pkg.mk"
