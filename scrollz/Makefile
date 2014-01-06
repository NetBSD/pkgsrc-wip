# $NetBSD: Makefile,v 1.2 2014/01/06 02:04:59 othyro Exp $
#

DISTNAME=	ScrollZ-2.2.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	chat
MASTER_SITES=	http://www.scrollz.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scrollz.com/
COMMENT=	Advanced IRC client based on ircII client
LICENSE=	modified-bsd # XXX ?

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		mandir
SUBST_FILES.mandir=	Makefile.in
SUBST_MESSAGE.mandir=	Fixing PKGMANDIR path.
SUBST_SED.mandir=	-e 's|@prefix@/share/man/man1|@mandir@/man1|1'
SUBST_STAGE.mandir=	pre-configure

.include "options.mk"

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scrollz.1

.include "../../mk/bsd.pkg.mk"
