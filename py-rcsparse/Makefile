# $NetBSD: Makefile,v 1.6 2009/05/19 09:00:11 thomasklausner Exp $

DISTNAME=	rcsparse-0.0.0_20061004
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://distfiles.scode.org/pkgsrc/

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/
COMMENT=	RCS parsing library for Python
LICENSE=	corecode-license

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25
PYDISTUTILSPKG=	# yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
