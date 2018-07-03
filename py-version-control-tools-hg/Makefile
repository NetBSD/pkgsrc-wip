# $NetBSD: Makefile,v 1.1 2015/01/18 09:20:27 thomasklausner Exp $

DISTNAME=	version-control-tools-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mercurial.selenic.com/wiki/MozillaPushlogExtension
COMMENT=	Mercurial extensions used by the mozilla project (incl. pushlog)
LICENSE=	gnu-gpl-v2

HG_REPOSITORIES=		version-control-tools
HG_REPO.version-control-tools=	https://hg.mozilla.org/hgcustom/version-control-tools/
WRKSRC=				${WRKDIR}/version-control-tools/hghooks

DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mercurial

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py

EGG_NAME=	Mozilla_Hg_Hooks-0.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
