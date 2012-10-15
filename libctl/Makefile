# $NetBSD: Makefile,v 1.4 2012/10/15 20:06:16 asau Exp $

DISTNAME=	libctl-3.2.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Control Language Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES=	c fortran77

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
