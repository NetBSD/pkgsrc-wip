# $NetBSD: Makefile,v 1.2 2013/11/02 13:01:38 makoto Exp $

DISTNAME=	texlive-20130530-source
#PKGNAME=	${DISTNAME:S/-source//}
PKGNAME=	texlive2013-0.2
#LICENSE=	texlive-license
#BROKEN=	Still getting ERROR: [check-interpreter.mk], and NOT fixed yet.

CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
MASTER_SITES+=	ftp://tug.org/texlive/historic/2013/
EXTRACT_SUFX=	.tar.xz

# only with include/kpathsea/absolute.h
CONFLICTS=	kpathsea-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tug.org/texlive/
COMMENT=	TeXLive Whole Distribution 2013

DEPENDS+=	ruby-[0-9]*:../../lang/ruby
# wanted wish installed
DEPENDS+=	tk-[0-9]*:../../x11/tk

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake perl pkg-config
USE_LIBTOOL=	yes

VPATHWRKDIR=	${WRKDIR}/build

# Make it to lower-case letters and add elf if applicable
# See around line 140 of ${PREFIX}/share/autoconfig/config.guess
# arm*|i386|m68k|ns32k|sh3*|sparc|vax)
.include "../../mk/bsd.prefs.mk"
.if (! empty(MACHINE_ARCH:Marm) || \
     ! empty(MACHINE_ARCH:Mi386) || \
     ! empty(MACHINE_ARCH:Msparc) || \
     ! empty(MACHINE_ARCH:Mvax) )
OPSYSL=		${OPSYS:tl}elf
PLIST_SUBST+=	OPSYS_L=
.else
OPSYSL=		${OPSYS:tl}
PLIST_SUBST+=	OPSYS_L=${OPSYS:tl}
.endif

REPLACE_RUBY=	texk/texlive/linked_scripts/convbkmk/convbkmk.rb
REPLACE_PYTHON=\
	texmf-dist/scripts/de-macro/de-macro \
	libs/harfbuzz/harfbuzz-0.9.15/src/gen-arabic-table.py \
	libs/harfbuzz/harfbuzz-0.9.15/src/gen-indic-table.py \
	texk/texlive/linked_scripts/de-macro/de-macro \
	texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
	texk/texlive/linked_scripts/ebong/ebong.py \
	texk/texlive/linked_scripts/dviasm/dviasm.py \
	texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
	texk/texlive/linked_scripts/dviasm/dviasm.py \
	libs/freetype2/freetype-2.4.11/src/tools/chktrcmp.py \
	libs/freetype2/freetype-2.4.11/src/tools/glnames.py \
	libs/freetype2/freetype-2.4.11/src/tools/docmaker/docbeauty.py \
	libs/freetype2/freetype-2.4.11/src/tools/docmaker/docmaker.py \
	libs/freetype2/freetype-2.4.11/builds/mac/ascii2mpw.py \
	texk/texlive/linked_scripts/ebong/ebong.py \
	texk/texlive/linked_scripts/texliveonfly/texliveonfly.py \
	utils/asymptote/GUI/xasyBezierEditor.py \
	utils/asymptote/GUI/xasyCodeEditor.py \
	utils/asymptote/GUI/CubicBezier.py \
	utils/asymptote/GUI/xasy.py \
	utils/asymptote/GUI/UndoRedoStack.py \
	utils/asymptote/GUI/xasyActions.py \
	utils/asymptote/GUI/xasyGUIIcons.py \
	utils/asymptote/GUI/xasyFile.py \
	utils/asymptote/GUI/xasyColorPicker.py \
	utils/asymptote/GUI/xasy2asy.py \
	utils/asymptote/GUI/xasyMainWin.py \
	utils/asymptote/GUI/xasyOptionsDialog.py \
	utils/asymptote/GUI/xasyOptions.py \


REPLACE_BASH=	\
	extra/xz/extra/7z2lzma/7z2lzma.bash \
	extra/xz/windows/build.bash \
	libs/teckit/TECkit-2.5.3/source/UpdateUnidata.sh \
	texk/dvisvgm/dvisvgm-1.2.2/tests/check-conv \
	texk/texlive/linked_scripts/dtxgen/dtxgen \
	texk/texlive/linked_scripts/ltxfileinfo/ltxfileinfo \
	texk/texlive/linked_scripts/bibexport/bibexport.sh \
	texk/texlive/linked_scripts/installfont/installfont-tl \
	texk/texlive/linked_scripts/arara/arara.sh \
	texk/texlive/linked_scripts/listbib/listbib \
	texk/texlive/linked_scripts/lua2dox/lua2dox_filter \
	texk/texlive/linked_scripts/latexfileversion/latexfileversion \

REPLACE_AWK=	libs/freetype2/freetype-2.4.11/builds/atari/deflinejoiner.awk

# See files/swap-shebang for REPLACE_PERL equivalent
SUBST_CLASSES+=		tlu
SUBST_STAGE.tlu=	post-patch
SUBST_MESSAGE.tlu=	Replacing /usr/bin/env texlua to ${PREFIX}/bin/texlua
SUBST_FILES.tlu=	\
	texk/texlive/linked_scripts/cachepic/cachepic.tlu \
	texk/texlive/linked_scripts/pfarrei/a5toa4.tlu \
	texk/texlive/linked_scripts/pfarrei/pfarrei.tlu \
	texk/texlive/linked_scripts/texdoc/texdoc.tlu \
	texk/texlive/linked_scripts/epspdf/epspdf.tlu \
	texk/texlive/linked_scripts/texlive/rungs.tlu

SUBST_SED.tlu=		'-e s,\#!/usr/bin/env texlua,\#!${PREFIX}/bin/texlua,'

SUBST_CLASSES+=		wish
SUBST_STAGE.wish=	post-patch
SUBST_MESSAGE.wish=	Replacing /usr/bin/env wish to ${PREFIX}/bin/wish
SUBST_FILES.wish=	texk/texlive/linked_scripts/epspdf/epspdftk.tcl
SUBST_SED.wish=		'-e s,\#!/usr/bin/env wish,\#!${PREFIX}/bin/wish,'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Adding ${PREFIX}/include for configure
SUBST_FILES.prefix=	configure texk/web2c/configure
SUBST_SED.prefix=	'-e s,@@PREFIX@@,${PREFIX},'

post-patch:
	(cd ${WRKDIR}; ${PERL5} ${FILESDIR}/subst-sheban -P ${PREFIX} )

do-configure:
	(if [ ! -d ${WRKDIR}/build ]; then ${MKDIR} ${VPATHWRKDIR};fi)
	(cd ${VPATHWRKDIR}; \
	env ${CONFIGURE_ENV} \
	sh ${WRKSRC}/configure --prefix=${PREFIX} ${CONFIGURE_ARGS})

do-build:
	(cd ${VPATHWRKDIR}; env ${MAKE_ENV} ${GMAKE} )

do-install:
	(cd ${VPATHWRKDIR}; env ${MAKE_ENV} DESTDIR=${DESTDIR} ${GMAKE} install)

# for interim solution
post-install:
	(cd ${DESTDIR}; \
	${PERL5} ${FILESDIR}/subst-sheban \
	 -P ${PREFIX} \
	 -p python${PYVERSSUFFIX} \
	 -r ${RUBY} \
         -t ${MACHINE_ARCH}-unknown-${OPSYSL}${OS_VERSION}/texlua \
	 -d \
	)
.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# for native only
#include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
#include "../../fonts/fontconfig/buildlink3.mk"
#include "../../x11/tk/buildlink3.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
# xdvik to find include/X11/Xaw.h
# configure: error: Sorry, you will need at least the Xaw header/library files to compile xdvik.
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
#include "../../mk/x11.builtin.mk"

.include "../../mk/bsd.pkg.mk"
