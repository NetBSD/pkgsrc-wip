# $NetBSD: Makefile,v 1.3 2004/04/25 08:33:45 blef Exp $
#

DISTNAME=		steghide-0.5.1
CATEGORIES=		wip
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
