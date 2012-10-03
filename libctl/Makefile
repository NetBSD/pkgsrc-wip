# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=	libctl-3.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Control Language Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES=	c fortran77

.include "../../lang/guile16/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
