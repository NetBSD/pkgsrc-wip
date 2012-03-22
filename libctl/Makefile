# $NetBSD: Makefile,v 1.1.1.1 2012/03/22 21:16:11 outpaddling Exp $
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

USE_LANGUAGES=	c fortran

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
