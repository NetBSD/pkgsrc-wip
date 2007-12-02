# $NetBSD: Makefile,v 1.4 2007/12/02 14:50:13 hoka_adam Exp $
#

DISTNAME=	eet-0.9.10.041
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Distribution Container Library and Tools

GNU_CONFIGURE=	YES
USE_LIBTOOL=    YES
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
.include "../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
