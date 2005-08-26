# $NetBSD: Makefile,v 1.6 2005/08/26 17:59:14 poppnk Exp $
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

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
