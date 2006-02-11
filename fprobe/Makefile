# $NetBSD: Makefile,v 1.1 2006/02/11 23:59:08 christian_gall Exp $
#

DISTNAME=		fprobe-1.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fprobe/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://fprobe.sourceforge.net/
COMMENT=		collect network traffic data and emit it as NetFlow flows

GNU_CONFIGURE=		yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
