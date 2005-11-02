# $NetBSD: Makefile,v 1.1.1.1 2005/11/02 02:25:37 poppnk Exp $
#

DISTNAME=		btscanner-2.0
CATEGORIES=		wip net security
MASTER_SITES=		http://www.pentest.co.uk/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pentest.co.uk/src/
COMMENT=		Bluetooth device information viewer
# XXX The comment may be changed

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
