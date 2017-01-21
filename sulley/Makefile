PKGNAME=	sulley-1.0.20161018
CATEGORIES=	net security

GIT_REPOSITORIES=	OpenRCE
GIT_REPO.OpenRCE=	git://github.com/OpenRCE/sulley.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenRCE/sulley
COMMENT=	pure-python fully automated and unattended fuzzing framework
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/OpenRCE

# XXX tests fail the first time
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} unit_test.py

PYTHON_VERSIONS_ACCEPTED=	27
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
