# $NetBSD: Makefile,v 1.5 2005/07/29 13:54:18 obache Exp $

DISTNAME=	foomatic-db-3.0-20050729
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters-[0-9]*:../../print/foomatic-filters

WRKSRC=		${WRKDIR}/foomatic-db-20050729		# XXX HACK ALERT

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
