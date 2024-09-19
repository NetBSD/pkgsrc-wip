# $NetBSD$

DISTNAME=	RepeatMasker-4.1.2-p1
PKGNAME=	repeatmasker-4.1.2.1
CATEGORIES=	biology
MASTER_SITES=	http://www.repeatmasker.org/RepeatMasker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.repeatmasker.org/RepeatMasker/
COMMENT=	Find interspersed repeats and low complexity DNA sequences
LICENSE=	osl # v2.1 but licenses/osl is v3.0

WRKSRC=		${WRKDIR}/RepeatMasker
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax perl
NO_BUILD=	yes

DEPENDS+=	${PYPKGPREFIX}-h5py>=2.9.0:../../devel/py-h5py
DEPENDS+=	trf>=4.09.1:../../wip/trf

# use options? crossmatch, rmblast, nhmmer, abblast/wublast
# valid search engine values: ncbi|rmblast|wublast|abblast|crossmatch|hmmer|nhmmer
CONFIGURE_ARGS+=	-default_search_engine=hmmer
DEPENDS+=		hmmer>=3.1:../../wip/hmmer

CONFIGURE_ARGS+=	-abblast_dir=${PREFIX}/bin
CONFIGURE_ARGS+=	-crossmatch_dir=${PREFIX}/bin
CONFIGURE_ARGS+=	-hmmer_dir=${PREFIX}/bin
CONFIGURE_ARGS+=	-rmblast_dir=${PREFIX}/bin

CONFIGURE_ARGS+=	-trf_prgm=${PREFIX}/bin/trf

PYTHON_VERSIONS_INCOMPATIBLE=	27
SUBST_CLASSES+=			python3
SUBST_STAGE.python3=		pre-configure
SUBST_FILES.python3=		configure
SUBST_VARS.python3=		PYTHONBIN

REPLACE_PERL+=		*.pm
REPLACE_PERL+=		configure
REPLACE_PERL+=		util/*.pl
REPLACE_PERL+=		util/trfMask
REPLACE_PYTHON+=	famdb.py
REPLACE_PYTHON+=	util/RM2Bed.py

# XXX - LIBDIR is used to find the location of files when installed
# programs are run.  However, configure tests for distributed files in
# ${LIBDIR} when it runs.  Thus, LIBDIR cannot point to a directory
# first created during installation, so the default is used initially
# then replaced prior to installation.
#
SUBST_CLASSES+=		LIBDIR
SUBST_STAGE.LIBDIR=	pre-install
SUBST_FILES.LIBDIR=	RepeatMaskerConfig.pm
SUBST_SED.LIBDIR=	-e "s,'value' => '.*/RepeatMasker/Libraries','value' => '${PREFIX}/RepeatMasker/Libraries',"

post-extract:
	${CHMOD} a-x ${WRKSRC}/Libraries/Artefacts.embl
	${CHMOD} a-x ${WRKSRC}/Libraries/RepeatAnnotationData.pm

do-configure:
	cd ${WRKSRC} && ${ENV} ${CONFIGURE_ENV} ${PERL5} configure ${CONFIGURE_ARGS}

INSTALLATION_DIRS+=	RepeatMasker lib/RepeatMasker share/doc/RepeatMasker
DOC_FILES+=		README.md daterepeats.help repeatmasker.help
# XXX - easier to copy everything and delete a few files
UNINSTALLED_FILES+=	.github INSTALL LICENSE ReleaseNotes configure.orig ${DOC_FILES}

pre-install:
	cd ${WRKSRC}/Libraries && ${LN} -sf Dfam.h5 RepeatMaskerLib.h5

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${PREFIX}/RepeatMasker
	cd ${DESTDIR}${PREFIX}/RepeatMasker && ${RM} -rf ${UNINSTALLED_FILES}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/RepeatMasker
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../wip/ncbi-blast+/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
