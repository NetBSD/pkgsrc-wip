# $NetBSD: Makefile,v 1.4 2004/04/11 23:37:43 blef Exp $
#

DISTNAME=		bub-n-bros-1.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bub-n-bros/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://bub-n-bros.sourceforge.net/
COMMENT=		Multiplayer crazy clone of Bubble Bobble

WRKSRC=			${WRKDIR}/bub-n-bros
USE_X11=		yes
PY_PATCHPLIST=		yes
USE_BUILDLINK3=		yes

MAKE_ENV=		CFLAGS="${CFLAGS}"
MAKE_ENV+=		LDFLAGS="${LDFLAGS}"

PYTHON_VERSIONS_ACCEPTED= 23 23pth 22 22pth

PYTHON_PATCH_SCRIPTS=	pclient-pygame.py
PYTHON_PATCH_SCRIPTS+=	pclient-slow-X.py
PYTHON_PATCH_SCRIPTS+=	pclient-xshm.py
PYTHON_PATCH_SCRIPTS+=	bubbob/bb.py
PYTHON_PATCH_SCRIPTS+=	bubbob/doc/bonus-doc.py
PYTHON_PATCH_SCRIPTS+=	display/pclient.py
PYTHON_PATCH_SCRIPTS+=	display/playback.py

PAX_SUBST=	-s ',*/setup.py,,' -s ',*/setup.py.pre,,'

post-patch:
	${MV} ${WRKSRC}/display/setup.py ${WRKSRC}/display/setup.py.pre
	${SED}  -e "s,@X11BASE@,${X11BASE},g" \
		${WRKSRC}/display/setup.py.pre > ${WRKSRC}/display/setup.py
do-build:
	cd ${WRKSRC}/display && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC}/bubbob && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC}/display && ${PYTHONBIN} setup.py clean
	cd ${WRKSRC}/bubbob && ${PYTHONBIN} setup.py clean
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/games/${PKGBASE}
	cd ${WRKSRC} && ${PAX} ${PAX_SUBST} \
		-rwpe . ${PREFIX}/games/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../wip/py-game/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
