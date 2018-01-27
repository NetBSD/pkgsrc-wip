# $NetBSD$
#

PKGNAME=	cronolog-devel-1.7.1
DISTNAME=	cronolog-1.7.1-beta
CATEGORIES=	www
MASTER_SITES=	http://BSDforge.com/projects/source/sysutils/cronolog-devel/
EXTRACT_SUFX=	.tar.xz
WRKSRC=		${WRKDIR}/cronolog-1.7.1

MAINTAINER=	otis@sk.FreeBSD.org
HOMEPAGE=	http://www.freshports.org/sysutils/cronolog-devel/
COMMENT=	Web log rotation utility that provides datestamp filenames
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
INFO_FILES=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

SUBST_CLASSES+=	cl
SUBST_STAGE.cl=	pre-configure
SUBST_FILES.cl=	doc/cronolog.1m
SUBST_SED.cl=	-e "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && mv man1/cronolog.1m man8/cronolog.8
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && mv man1/cronosplit.1m man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
