# $NetBSD: Makefile,v 1.23 2014/01/25 10:45:27 thomasklausner Exp $

DISTNAME=		bubbros-1.6.2
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bub-n-bros/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bub-n-bros.sourceforge.net/
COMMENT=		Multiplayer crazy clone of Bubble Bobble
LICENSE=		mit

PY_PATCHPLIST=		yes

MAKE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=		LDFLAGS=${LDFLAGS:M*:Q}

USE_TOOLS+=		pax

REPLACE_PYTHON+=	BubBob.py
REPLACE_PYTHON+=	bubbob/bb.py
REPLACE_PYTHON+=	bubbob/setup.py
REPLACE_PYTHON+=	display/setup.py
REPLACE_PYTHON+=	display/setup.py.pre
REPLACE_PYTHON+=	bubbob/doc/bonus-doc.py
REPLACE_PYTHON+=	display/pclient.py
REPLACE_PYTHON+=	display/playback.py
REPLACE_PYTHON+=	http2/sf/bb12.py

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/games/${PKGBASE}
	cd ${WRKSRC} && pax ${PAX_SUBST} \
		-rwpe . ${DESTDIR}${PREFIX}/games/${PKGBASE}
	find ${DESTDIR}${PREFIX} -name *.orig -delete
	find ${DESTDIR}${PREFIX} -name .cvsignore -delete
	find ${DESTDIR}${PREFIX} -name Entries -delete
	find ${DESTDIR}${PREFIX} -name Entries.Log -delete
	find ${DESTDIR}${PREFIX} -name Repository -delete
	find ${DESTDIR}${PREFIX} -name Root -delete
	find ${DESTDIR}${PREFIX} -name CVS -exec rmdir {} \; 2>/dev/null || ${TRUE}

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../devel/py-game/buildlink3.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
