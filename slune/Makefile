# $NetBSD: Makefile,v 1.18 2014/05/09 07:38:52 thomasklausner Exp $

DISTNAME=		Slune-0.6.1
PKGNAME=		${PYPKGPREFIX}-Slune-0.6.1
CATEGORIES=		games
MASTER_SITES=		http://download.gna.org/slune/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/oomadness/en/slune/index.html
COMMENT=		Action game, featuring cars, races and Tux the Penguin

DEPENDS+=		${PYPKGPREFIX}-Py2Play>=0.1.6:../../wip/py-Py2Play
DEPENDS+=		${PYPKGPREFIX}-Soya>=0.6.1:../../wip/py-Soya
DEPENDS+=		${PYPKGPREFIX}-EditObj2-[0-9]*:../../wip/py-EditObj2
DEPENDS+=		${PYPKGPREFIX}-vorbis>=1.3:../../audio/py-vorbis


PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-vorbis, py-EditObj2

PYSETUPINSTALLARGS=	--install-lib ${PYSITELIB} --install-scripts ${PREFIX}/bin --install-data ${PREFIX}/share/

PYFILES= \
	__init__.py character.py circuit_generator.py controler.py \
	fight.py freestyle.py globdef.py gui.py gui_gl.py \
	gui_option.py hunt.py ia_algogen.py init_editobj.py level.py \
	player.py race.py race_algogen.py race_algogen2.py \
	sound.py videosequence.py

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/slune
	for a in ${PYFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/${PYSITELIB}/slune/$$a ; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
