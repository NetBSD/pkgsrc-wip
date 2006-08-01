# $NetBSD: Makefile,v 1.1.1.1 2006/08/01 21:24:29 scode Exp $

DISTNAME=	cvs20hg-0.0.0_20060723
PKGNAME=	${PYPKGPREFIX}-cvs20hg-0.0.0_20060723
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.scode.org/pkgsrc/

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/cvs20hg/
COMMENT=	CVS->Mercurial conversion tool

PYTHON_VERSIONS_ACCEPTED=24
PYDISTUTILSPKG=	# yes

# BUG: We require devel/mercurial to be installed with python2.4, but
# this is not enforced. Pending change of devel/mercurial to fix this
# issue.

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
