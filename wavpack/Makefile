# $NetBSD: Makefile,v 1.1.1.1 2006/04/24 13:58:14 tnn2 Exp $

DISTNAME=		wavpack-4.32
CATEGORIES=		audio
MASTER_SITES=		http://www.wavpack.com/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://www.wavpack.com/
COMMENT=		Audio codec for lossless, lossy and hybrid compression

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	wavpack.pc.in
USE_LIBTOOL=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
