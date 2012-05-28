# $NetBSD: Makefile,v 1.2 2012/05/28 14:09:28 outpaddling Exp $
#

DISTNAME=	libctl-3.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Control Language Library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES=	c fortran77

.include "../../lang/guile16/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
