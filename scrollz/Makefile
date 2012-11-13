# $NetBSD: Makefile,v 1.1 2012/11/13 12:53:54 othyro Exp $
#

DISTNAME=	ScrollZ-2.2.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.scrollz.com/pub/ScrollZ/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=	Advanced IRC client based on ircII client
LICENSE=	modified-bsd # XXX ?

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes

.include "options.mk"

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scrollz.1


.include "../../mk/bsd.pkg.mk"
