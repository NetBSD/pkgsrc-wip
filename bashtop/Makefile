# $NetBSD$

DISTNAME=	bashtop-0.9.25
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/aristocratos/bashtop/
COMMENT=	Linux/OSX/FreeBSD resource monitor
LICENSE=	apache-2.0

USE_TOOLS=	bash:run
RUN_DEPENDS=	${PYPKGPREFIX}-psutil>=5.7.0:../../sysutils/py-psutil

USE_LANGUAGES=	# none
NO_BUILD=	yes

SUBST_CLASSES+=			fix-python-interp
SUBST_STAGE.fix-python-interp=	pre-install
SUBST_FILES.fix-python-interp=	bashtop
SUBST_SED.fix-python-interp=	-e 's|python3|${PYTHONBIN}|g'

REPLACE_BASH=	bashtop

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bashtop ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
