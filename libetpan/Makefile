# $NetBSD: Makefile,v 1.1.1.1 2004/02/02 02:39:46 dawszy Exp $
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
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
