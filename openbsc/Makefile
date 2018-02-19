# $NetBSD: Makefile,v 1.4 2012/11/13 22:25:39 othyro Exp $
#

DISTNAME=	openbsc-0.9.13
CATEGORIES=	devel
MASTER_SITES=	http://openbsc.osmocom.org/trac/raw-attachment/wiki/Tarballs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://openbsc.osmocom.org/
COMMENT=	Free software implementation for GSM/3GPP protocol stack and elements
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	openbsc.pc.in

GNU_CONFIGURE=	yes

.include "../../wip/libosmocore/buildlink3.mk"
.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
