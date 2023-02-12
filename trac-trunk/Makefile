# $NetBSD: Makefile,v 1.90 2020/07/27 15:22:12 gdt Exp $

DISTNAME=	Trac-1.5.4.dev0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www devel
# This master site is unlikely to have stable distinfo, but it's what we've got.
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/incoming/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://trac.edgewall.org/
COMMENT=	Repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

# Updates to micro-releases along stable branches are commited without
# testing.
#
# Trac supports svn and git in the base, plus others via plugins,
# using them at runtime if configured.  Therefore this package does
# not depend on svn or git to avoid installing them for trac installs
# that use the other.

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11:../../textproc/py-jinja2

USE_TOOLS+=	pax

# Trac 1.5.4 accepts 3.5+, but pkgsrc only knows about 3.7+
PYTHON_VERSIONS_ACCEPTED=	37 38 39 310 311

REPLACE_PYTHON=		contrib/*.py contrib/*-hook
REPLACE_PYTHON+=	trac/tests/functional/*.py

.include "../../lang/python/application.mk"

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/contrib && pax -rwppm -s ',./rpm/.*$$,,' -s ',./rpm$$,,' \
		. ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
