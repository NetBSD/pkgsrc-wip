# $NetBSD: Makefile,v 1.4 2004/06/13 18:56:26 thomasklausner Exp $

DISTNAME=	foomatic-filters-cups-3.0.1
CATEGORIES=	print
MASTER_SITES=	#
DISTFILES=

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	CUPS support for foomatic-filters

DEPENDS+=	foomatic-filters-3.0*:../../wip/foomatic-filters

NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ../../../bin/foomatic-rip ${PREFIX}/libexec/cups/filter

.include "../../mk/bsd.pkg.mk"
