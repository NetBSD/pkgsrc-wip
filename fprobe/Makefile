# $NetBSD: Makefile,v 1.2 2006/11/11 11:31:04 shattered Exp $
#

DISTNAME=		fprobe-1.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fprobe/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://fprobe.sourceforge.net/
COMMENT=		Collect network traffic data and emit it as NetFlow flows

GNU_CONFIGURE=		yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
