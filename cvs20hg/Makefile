# $NetBSD: Makefile,v 1.2 2006/08/01 22:20:36 scode Exp $

DISTNAME=	cvs20hg-0.0.0_20060723
PKGNAME=	${PYPKGPREFIX}-cvs20hg-0.0.0_20060723
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.scode.org/pkgsrc/

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/cvs20hg/
COMMENT=	CVS->Mercurial conversion tool

PYTHON_VERSIONS_ACCEPTED=24
PYDISTUTILSPKG=	# yes

DEPENDS+=	${PYPKGPREFIX}-rcsparse-0.0.0_20060723nb1:../../wip/py-rcsparse

# BUG: We require devel/mercurial to be installed with python2.4, but
# this is not enforced. Pending change of devel/mercurial to fix this
# issue. In fact we cannot depent on devel/mercurial at all due to
# issues with PKGNAMNE_REQD and PYTHON_VERSION_REQD. Users will need
# to manually install devel/mercurial for this package to work.

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
