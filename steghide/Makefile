# $NetBSD: Makefile,v 1.2 2003/12/30 23:57:35 cjep Exp $
#

DISTNAME=		steghide-0.5.1
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=steghide/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://steghide.sourceforge.net/
COMMENT=		steganography program that is able to hide data

DEPENDS+=	mcrypt-*:../../security/mcrypt

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../security/mhash/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
