# $NetBSD: Makefile,v 1.5 2012/04/08 19:09:42 thomasklausner Exp $

DISTNAME=	cvs20hg-0.0.0_20061004
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.scode.org/pkgsrc/

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/cvs20hg/
COMMENT=	CVS->Mercurial conversion tool

PYTHON_VERSIONS_ACCEPTED=	25
PYDISTUTILSPKG=	# yes

DEPENDS+=	${PYPKGPREFIX}-rcsparse-0.0.0_20061004:../../wip/py-rcsparse

# BUG: We require devel/mercurial to be installed with python2.4, but
# this is not enforced. Pending change of devel/mercurial to fix this
# issue. In fact we cannot depent on devel/mercurial at all due to
# issues with PKGNAMNE_REQD and PYTHON_VERSION_REQD. Users will need
# to manually install devel/mercurial for this package to work.

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
