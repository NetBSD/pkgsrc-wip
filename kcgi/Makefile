# $NetBSD$

DISTNAME=	kcgi-0.13.3
CATEGORIES=	www
MASTER_SITES=	https://kristaps.bsd.lv/kcgi/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://kristaps.bsd.lv/kcgi/
COMMENT=	CGI/FCGI library for C/C++ web apps
LICENSE=	isc

SUBST_CLASSES+=		install
SUBST_SED.install+=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.install+=	-e 's,^MANDIR=.*,MANDIR=${PREFIX}/${PKGMANDIR},'
SUBST_SED.install+=	-e '/^CC=.*/d'
SUBST_SED.install+=	-e '/^CFLAGS=.*/d'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

HAS_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
