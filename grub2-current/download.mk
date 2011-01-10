# $NetBSD: download.mk,v 1.7 2011/01/10 00:15:51 gregoire Exp $
#

USE_TOOLS+=		ftp
BUILD_DEPENDS+=		bzr>=1.0:../../devel/bzr
BUILD_DEPENDS+=		rsync>=3.0:../../net/rsync

DISTFILES?=		# empty
BZR_REPOSITORY=		http://bzr.savannah.gnu.org/r/grub/trunk/grub
BZR_REVISION=		3040
UNIFONT_URL=		http://unifoundry.com/unifont-5.1.20080820.pcf.gz
UNIFONT_EXT=		pcf.gz

pre-extract: do-bzr-extract

.PHONY: do-bzr-extract
do-bzr-extract:
	${RUN} set -e;								\
	cd ${WRKDIR};								\
	${STEP_MSG} "Exporting from bazaar repository "${BZR_REPOSITORY};	\
	bzr export -r ${BZR_REVISION} ${DISTNAME} ${BZR_REPOSITORY}

post-extract: do-get-translations

.PHONY: do-get-translations
do-get-translations:
	cd ${WRKSRC} && rsync -Lrtvz translationproject.org::tp/latest/grub/ po
	cd ${WRKSRC}/po && (ls *.po | sed -e 's,\.po$$,,') > LINGUAS
.if !empty(PKG_OPTIONS:Mgrub-mkfont)
	cd ${WRKSRC} && ftp -o unifont.${UNIFONT_EXT} ${UNIFONT_URL}
.endif

pre-configure: do-autogen

.PHONY: do-autogen
do-autogen:
	cd ${WRKSRC} && ./autogen.sh

# The script autogen.sh uses python.
PYTHON_FOR_BUILD_ONLY=	yes
SUBST_CLASSES+=		fix-py
SUBST_STAGE.fix-py=	pre-configure
SUBST_MESSAGE.fix-py=	Replacing python executable in autogen.sh.
SUBST_FILES.fix-py=	autogen.sh
SUBST_SED.fix-py=	-e 's,^python,${PYTHONBIN},g'

.include "../../lang/python/pyversion.mk"
