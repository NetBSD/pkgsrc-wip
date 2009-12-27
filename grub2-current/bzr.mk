# $NetBSD: bzr.mk,v 1.2 2009/12/27 00:14:01 gregoire Exp $
#

BUILD_DEPENDS+=		bzr>=1.0:../../devel/bzr

DISTFILES?=		# empty
BZR_REPOSITORY=		http://bzr.savannah.gnu.org/r/grub/trunk/grub

pre-extract: do-bzr-extract

.PHONY: do-bzr-extract
do-bzr-extract:
	${RUN} set -e;								\
	cd ${WRKDIR};								\
	${STEP_MSG} "Exporting from bazaar repository "${BZR_REPOSITORY};	\
	bzr export ${DISTNAME} ${BZR_REPOSITORY}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# The script autogen.sh uses python and ruby.
PYTHON_FOR_BUILD_ONLY=	yes
SUBST_CLASSES+=		fix-py
SUBST_STAGE.fix-py=	pre-configure
SUBST_MESSAGE.fix-py=	Appending python version in autogen.sh.
SUBST_FILES.fix-py=	autogen.sh
SUBST_SED.fix-py=	-e 's,^python,python${PYVERSSUFFIX},g'
BUILD_DEPENDS+=		ruby>=1.8:../../lang/ruby

.include "../../lang/python/pyversion.mk"
