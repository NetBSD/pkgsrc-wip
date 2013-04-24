# $NetBSD: Makefile,v 1.9 2013/04/24 02:27:59 othyro Exp $
#

DISTNAME=	ispell-lt-1.2
PKGNAME=	ispell-lietuviu-1.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.akl.lt/ispell-lt/

MAINTAINER=	tomas.furmonavicius@takas.lt
HOMEPAGE=	http://www.lietuvybe.org/?menuid=Zodynai&submenu=ispell-lt
COMMENT=	Lithuanian dictionary for ispell
LICENSE=	modified-bsd

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python paths.
SUBST_FILES.fix-python=		tools/*.py
SUBST_SED.fix-python=		-e 's,/usr/bin/python,${PYTHONBIN},g'
SUBST_SED.fix-python+=		-e 's,env python,env ${PYTHONBIN},g'

SUBST_CLASSES+=		install
SUBST_FILES.install=	Makefile
SUBST_MESSAGE.install=	Fixing DESTDIR path and install user/group.
SUBST_SED.install=	-e "s|installdir=|installdir=${DESTDIR}|1"
SUBST_SED.install+=	-e 's/-g 0 -o 0//g'
SUBST_STAGE.install=	pre-configure

BUILD_TARGET=		lietuviu.hash
INSTALLATION_DIRS+=	lib

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
