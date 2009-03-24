# $NetBSD: Makefile,v 1.5 2009/03/24 10:10:00 jihbed Exp $

DISTNAME=	rcsparse-0.0.0_20061004
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://distfiles.scode.org/pkgsrc/

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/
COMMENT=	RCS parsing library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	corecode-license

PYTHON_VERSIONS_ACCEPTED=	25
PYDISTUTILSPKG=	# yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
