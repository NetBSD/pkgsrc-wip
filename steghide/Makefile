# $NetBSD: Makefile,v 1.4 2004/07/18 15:08:35 ppostma Exp $
#

DISTNAME=		steghide-0.5.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		Steganography program that is able to hide data

DEPENDS+=		mcrypt-*:../../security/mcrypt

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/mhash/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
