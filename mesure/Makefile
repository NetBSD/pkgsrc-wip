# $NetBSD: Makefile,v 1.7 2005/08/26 18:22:06 poppnk Exp $
#

DISTNAME=		mesure-0.5
CATEGORIES=		wip sysutils
MASTER_SITES=		http://cvs.nopcode.org/ftp/mesure/\
			ftp://ftp.nopcode.org/prj/mesure/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mesure
COMMENT=		Tool to measure different kind of streams
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

NOT_FOR_PLATFORM+=	OpenBSD-*-*

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
