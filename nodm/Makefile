# $NetBSD: Makefile,v 1.1 2013/04/07 20:54:18 khorben Exp $
#

DISTNAME=	nodm-0.7
CATEGORIES=	x11
MASTER_SITES=	http://enricozini.org/sw/nodm/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://enricozini.org/sw/nodm/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS=	gmake

DEPENDS+=	help2man>=1.36:../../converters/help2man

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
