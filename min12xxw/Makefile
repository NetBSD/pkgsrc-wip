# $NetBSD: Makefile,v 1.1 2007/08/21 01:18:09 bsadewitz Exp $
#

DISTNAME=	min12xxw-0.0.9
CATEGORIES=	print
MASTER_SITES=	http://www.hinterbergen.de/mala/min12xxw/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.hinterbergen.de/mala/min12xxw/
COMMENT=	Konica/Minolta PagePro 1[234]xx pbmraw stream converter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
