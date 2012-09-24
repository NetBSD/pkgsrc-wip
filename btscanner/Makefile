# $NetBSD: Makefile,v 1.4 2012/09/24 17:14:42 asau Exp $
#

DISTNAME=		btscanner-2.0
CATEGORIES=		net security
MASTER_SITES=		http://www.pentest.co.uk/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pentest.co.uk/cgi-bin/viewcat.cgi?cat=downloads
COMMENT=		Bluetooth device information viewer
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
