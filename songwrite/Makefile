# $NetBSD: Makefile,v 1.3 2004/05/09 23:40:46 blef Exp $
#

DISTNAME=		Songwrite-0.12
PKGNAME=		${DISTNAME:S/S/s/}
CATEGORIES=		misc
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oomadness.tuxfamily.org/en/songwrite/index.html
COMMENT=		Tablature (guitar partition) editor

DEPENDS+=		${PYPKGPREFIX}-EditObj-[0-9]*:../../wip/py-EditObj

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_PATCH_SCRIPTS=	songwrite

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

SW_FILES= 	__init__.py asciitab.py drum.py fourml.py globdef.py \
		gp3_loader.py init_editobj.py latex.py lilypond.py lyric.py \
		lyric2.py main.py midi_import.py player.py song.py \
		songbook.py staff.py stemml.py tablature.py ui.py view.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/songwrite ${PREFIX}/bin/songwrite-${PYVERSSUFFIX}
	for a in ${SW_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${PREFIX}/share/songwrite/$$a; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
