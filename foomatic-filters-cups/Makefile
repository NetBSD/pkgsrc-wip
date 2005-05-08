# $NetBSD: Makefile,v 1.5 2005/05/08 07:38:45 obache Exp $

DISTNAME=	foomatic-filters-cups-3.0.1
CATEGORIES=	print
MASTER_SITES=	#
DISTFILES=

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	CUPS support for foomatic-filters

DEPENDS+=	foomatic-filters-3.0*:../../print/foomatic-filters

NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${LN} -sf ../../../bin/foomatic-rip ${PREFIX}/libexec/cups/filter

.include "../../mk/bsd.pkg.mk"
