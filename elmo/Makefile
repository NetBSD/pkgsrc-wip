# $NetBSD: Makefile,v 1.1.1.1 2004/03/23 01:42:46 rockpiper Exp $
#

DISTNAME=		elmo-1.1.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=elmo/}

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://elmo.sourceforge.net
COMMENT=		The ELectronic Mail Operator is a console mail client

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/curses.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
