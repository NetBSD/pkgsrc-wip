# $NetBSD: Makefile,v 1.5 2010/05/28 05:38:00 othyro Exp $
#

DISTNAME=		ispell-lt-1.2
PKGNAME=		ispell-lietuviu-1.2
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.akl.lt/ispell-lt/

MAINTAINER=		tomas.furmonavicius@takas.lt
HOMEPAGE=		http://www.lietuvybe.org/?menuid=Zodynai&submenu=ispell-lt
COMMENT=		Lithuanian dictionary for ispell
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		ispell-base-[0-9]*:../../textproc/ispell-base

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python paths.
SUBST_FILES.fix-python=		tools/*.py
SUBST_SED.fix-python=		-e 's,/usr/bin/python,${PYTHONBIN},g'
SUBST_SED.fix-python+=		-e 's,env python,env ${PYTHONBIN},g'

BUILD_TARGET=		lietuviu.hash

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
