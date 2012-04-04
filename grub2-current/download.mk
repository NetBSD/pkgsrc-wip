# $NetBSD: download.mk,v 1.19 2012/04/04 22:13:52 gregoire Exp $
#

#
# Helper file to access the bazaar repository, download extra stuff (such as
# translations), and generate the configure script with autogen.sh.
#

BUILD_DEPENDS+=		bzr>=1.0:../../devel/bzr
BUILD_DEPENDS+=		rsync>=3.0:../../net/rsync
BUILD_DEPENDS+=		autogen>=5.9:../../devel/autogen

DISTFILES?=		# empty
BZR_REPOSITORY=		bzr://bzr.savannah.gnu.org/grub/trunk/grub
BZR_REVISION=		4206

pre-extract: do-bzr-extract

.PHONY: do-bzr-extract
do-bzr-extract:
	${RUN} set -e;								\
	cd ${WRKDIR};								\
	${STEP_MSG} "Exporting from bazaar repository "${BZR_REPOSITORY};	\
	bzr export -r ${BZR_REVISION} ${DISTNAME} ${BZR_REPOSITORY}

post-extract: do-extra-downloads

.PHONY: do-extra-downloads
do-extra-downloads:
	cd ${WRKSRC} && rsync -Lrtvz translationproject.org::tp/latest/grub/ po
	cd ${WRKSRC}/po && (ls *.po | sed -e 's,\.po$$,,') > LINGUAS

pre-configure: do-autogen

.PHONY: do-autogen
do-autogen:
	cd ${WRKSRC} && ./autogen.sh

# Python is used to generate the autogen makefile template.
PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		gentpl.py
SUBST_CLASSES+=		fix-py
SUBST_STAGE.fix-py=	post-patch
SUBST_MESSAGE.fix-py=	Replacing python executable in autogen.sh.
SUBST_FILES.fix-py=	autogen.sh conf/Makefile.common
SUBST_SED.fix-py=	-e 's,^\([	]*\)python ,\1${PYTHONBIN} ,g'

.include "../../lang/python/application.mk"
