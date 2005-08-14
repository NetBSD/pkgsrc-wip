# $NetBSD: Makefile,v 1.6 2005/08/14 11:13:36 obache Exp $

DISTNAME=	foomatic-db-3.0-20050814
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters-[0-9]*:../../print/foomatic-filters

WRKSRC=		${WRKDIR}/foomatic-db-20050729		# XXX HACK ALERT

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
