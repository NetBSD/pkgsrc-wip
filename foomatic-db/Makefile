# $NetBSD: Makefile,v 1.4 2005/05/08 07:33:18 obache Exp $

DISTNAME=	foomatic-db-20050508
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters-[0-9]*:../../print/foomatic-filters

WRKSRC=		${WRKDIR}/foomatic-db-20050508		# XXX HACK ALERT

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
