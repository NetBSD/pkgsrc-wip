# $NetBSD: Makefile,v 1.1.1.1 2004/03/21 21:16:54 bjan2 Exp $

DISTNAME=	foomatic-db-current
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters-[0-9]*:../../wip/foomatic-filters

WRKSRC=		${WRKDIR}/foomatic-db-20040319		# XXX HACK ALERT

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
