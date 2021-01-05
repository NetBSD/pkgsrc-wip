# $NetBSD$

DISTNAME=	kcgi-0.12.2
CATEGORIES=	www
MASTER_SITES=	https://kristaps.bsd.lv/kcgi/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://kristaps.bsd.lv/kcgi/
COMMENT=	CGI/FCGI library for C/C++ web apps
LICENSE=	isc

SUBST_CLASSES+=		install
SUBST_SED.install+=	-e 's,/usr/local,${PREFIX},'				\
			-e 's,^MANDIR=.*,MANDIR=${PREFIX}/${PKGMANDIR},'	\
			-e '/^CC=.*/d'						\
			-e '/^CFLAGS=.*/d'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

HAS_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
