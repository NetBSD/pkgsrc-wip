# $NetBSD: Makefile,v 1.5 2004/04/28 00:13:17 blef Exp $
#

DISTNAME=		libetpan-0.32
CATEGORIES=		devel mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/
COMMENT=		Really nice mail library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
