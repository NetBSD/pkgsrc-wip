# $NetBSD: Makefile,v 1.7 2012/12/27 03:06:57 othyro Exp $
#

DISTNAME=	ispell-lt-1.2
PKGNAME=	ispell-lietuviu-1.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.akl.lt/ispell-lt/

MAINTAINER=	tomas.furmonavicius@takas.lt
HOMEPAGE=	http://www.lietuvybe.org/?menuid=Zodynai&submenu=ispell-lt
COMMENT=	Lithuanian dictionary for ispell
LICENSE=	modified-bsd

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python paths.
SUBST_FILES.fix-python=		tools/*.py
SUBST_SED.fix-python=		-e 's,/usr/bin/python,${PYTHONBIN},g'
SUBST_SED.fix-python+=		-e 's,env python,env ${PYTHONBIN},g'

SUBST_CLASSES+=		destdir
SUBST_FILES.destdir=	Makefile
SUBST_MESSAGE.destdir=	Fixing DESTDIR path.
SUBST_SED.destdir=	-e "s|installdir=|installdir=${DESTDIR}|1"
SUBST_STAGE.destdir=	pre-configure

BUILD_TARGET=		lietuviu.hash
INSTALLATION_DIRS+=	lib

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
