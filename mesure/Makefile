# $NetBSD: Makefile,v 1.5 2005/08/10 06:59:59 poppnk Exp $
#

DISTNAME=		mesure-0.4
CATEGORIES=		wip sysutils
MASTER_SITES=		ftp://ftp.nopcode.org/prj/mesure/ \
			http://www.nopcode.org/ftp/mesure/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mesure
COMMENT=		Tool to measure different kind of streams
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
