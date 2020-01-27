# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:42 thomasklausner Exp $

DISTNAME=	jokosher-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://launchpad.net/jokosher/trunk/0.11.5/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jokosher.org/
COMMENT=	Simple, yet powerful, multi-track studio
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.19:../../devel/py-xdg
INSTALLATION_DIRS+=	bin share/jokosher share/mime/packages

SUBST_CLASSES+=		share
SUBST_FILES.share=	bin/jokosher build/scripts-${PYVERSSUFFIX}/jokosher
SUBST_FILES.share+=	setup.py
SUBST_MESSAGE.share=	Fixing PREFIX/share path.
SUBST_STAGE.share=	pre-install
SUBST_SED.share=	-e 's,/usr/share/,${PREFIX}/share/,g'

REPLACE_PYTHON+=	Jokosher/JokosherApp.py Jokosher/Profiler.py

PY_PATCHPLIST=		yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR}

.include "../../textproc/rarian/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-gnonlin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
