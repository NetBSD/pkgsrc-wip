# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	fjd-0.1.42
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fjd/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nhoening/fjd/
COMMENT=	File-based job distribution for everyone
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-paramiko

USE_TOOLS+=	bash:run
USE_LANGUAGES=	# none

REPLACE_BASH+=	fjd/scripts/bgscreen

REPLACE_PYTHON+=	fjd/scripts/fjd-recruiter \
					fjd/scripts/fjd-worker \
					fjd/scripts/fjd-dispatcher


.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
DEPENDS+=	screen>=4.0.3:../../misc/screen
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.12.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-screenutils>=0.0.1.5.4:../../wip/py-screenutils
.include "../../mk/bsd.pkg.mk"
