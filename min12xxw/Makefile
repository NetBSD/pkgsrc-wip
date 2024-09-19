# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:55 asau Exp $

DISTNAME=	min12xxw-0.0.9
CATEGORIES=	print
MASTER_SITES=	http://www.hinterbergen.de/mala/min12xxw/
LICENSE=	gnu-gpl-v2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.hinterbergen.de/mala/min12xxw/
COMMENT=	Konica/Minolta PagePro 1[234]xx pbmraw stream converter

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
