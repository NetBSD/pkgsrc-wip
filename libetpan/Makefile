# $NetBSD: Makefile,v 1.4 2004/02/17 02:55:57 blef Exp $
#

DISTNAME=		libetpan-0.32
CATEGORIES=		devel mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/
COMMENT=		Really nice mail library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/pthread.buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
