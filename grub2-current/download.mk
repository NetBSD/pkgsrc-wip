# $NetBSD: download.mk,v 1.4 2010/06/07 00:55:25 gregoire Exp $
#

BUILD_DEPENDS+=		bzr>=1.0:../../devel/bzr
BUILD_DEPENDS+=		rsync>=3.0:../../net/rsync

DISTFILES?=		# empty
BZR_REPOSITORY=		http://bzr.savannah.gnu.org/r/grub/people/gsutre/fixes
UNIFONT_URL=		http://unifoundry.com/unifont-5.1.20080820.pcf.gz
UNIFONT_EXT=		pcf.gz

pre-extract: do-bzr-extract

.PHONY: do-bzr-extract
do-bzr-extract:
	${RUN} set -e;								\
	cd ${WRKDIR};								\
	${STEP_MSG} "Exporting from bazaar repository "${BZR_REPOSITORY};	\
	bzr export ${DISTNAME} ${BZR_REPOSITORY}

post-extract:
	cd ${WRKSRC} && rsync -Lrtvz  translationproject.org::tp/latest/grub/ po
.if !empty(PKG_OPTIONS:Mgrub-mkfont)
	cd ${WRKSRC} && ftp -o unifont.${UNIFONT_EXT} ${UNIFONT_URL}
.endif

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
