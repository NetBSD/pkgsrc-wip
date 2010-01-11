# $NetBSD: bzr.mk,v 1.4 2010/01/11 01:48:28 gregoire Exp $
#

BUILD_DEPENDS+=		bzr>=1.0:../../devel/bzr

DISTFILES?=		# empty
BZR_REPOSITORY=		http://bzr.savannah.gnu.org/r/grub/people/gsutre/netbsd

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
BUILD_DEPENDS+=		ruby>=1.6:../../lang/ruby

.include "../../lang/python/pyversion.mk"
