# $NetBSD: Makefile,v 1.1.1.1 2003/11/25 12:49:52 adrian_p Exp $
#

DISTNAME=	honeyd-0.7
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	Small daemon that creates virtual hosts on a network

DEPENDS+=       honeyd-arpd>=0.2:../../wip/honeyd-arpd

USE_PKGINSTALL=	YES
RCD_SCRIPTS=	honeyd

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../devel/libevent/buildlink2.mk"
.include "../../net/libdnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

