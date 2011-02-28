# $NetBSD: Makefile,v 1.19 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=		bubbros-1.6
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bub-n-bros/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bub-n-bros.sourceforge.net/
COMMENT=		Multiplayer crazy clone of Bubble Bobble

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE+=	25

MAKE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=		LDFLAGS=${LDFLAGS:M*:Q}

USE_TOOLS+=		pax

PYTHON_PATCH_SCRIPTS+=	bubbob/bb.py
PYTHON_PATCH_SCRIPTS+=	bubbob/doc/bonus-doc.py
PYTHON_PATCH_SCRIPTS+=	display/pclient.py
PYTHON_PATCH_SCRIPTS+=	display/playback.py
PYTHON_PATCH_SCRIPTS+=	http2/sf/bb12.py

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
	${INSTALL_DATA_DIR} ${DESDIR}${PREFIX}/games/${PKGBASE}
	cd ${WRKSRC} && pax ${PAX_SUBST} \
		-rwpe . ${DESDIR}${PREFIX}/games/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../devel/py-game/buildlink3.mk"

.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
