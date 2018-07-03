# $NetBSD: Makefile,v 1.2 2015/02/09 15:44:25 thomasklausner Exp $

DISTNAME=	gcalcli-3.4.0
CATEGORIES=	x11
MASTER_SITES=	https://github.com/insanum/gcalcli/
LICENSE=	mit

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/insanum/gcalcli/
COMMENT=	Command line interface to Google Calendar 

GIT_REPOSITORIES=	gcalcli
GIT_REPO.gcalcli=	git://github.com/insanum/gcalcli.git
WRKSRC=			${WRKDIR}/gcalcli

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-gflags-[0-9]*:../../devel/py-gflags
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client-[0-9]*:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-parsedatetime-[0-9]*:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gflags

.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
