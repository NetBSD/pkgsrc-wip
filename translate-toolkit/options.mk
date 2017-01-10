# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.translate-toolkit
PKG_SUPPORTED_OPTIONS+=		lxml levenshtein chardet tradostm doc
PKG_SUGGESTED_OPTIONS=		lxml chardet tradostm doc
PLIST_VARS+=			doc


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlxml)
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5:../../textproc/py-lxml
.endif

.if !empty(PKG_OPTIONS:Mlevenshtein)
PKG_FAIL_REASON+=	"You will need to install python-Levenshtein manually using pip"
.endif

.if !empty(PKG_OPTIONS:Mchardet)
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.3:../../converters/py-chardet
.endif

.if !empty(PKG_OPTIONS:Mtradostm)
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3:../../www/py-beautifulsoup4
.endif

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0.4:../../textproc/py-sphinx
SUBST_CLASSES+=		sphinx
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},"
SUBST_FILES.sphinx+=	docs/Makefile
SUBST_STAGE.sphinx=	pre-configure
SUBST_MESSAGE.sphinx=	Fix sphinx command names.
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
PLIST.doc=	yes

pre-build:
		${MKDIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
		cd ${WRKSRC}/docs && ${MAKE} man
		${INSTALL_MAN} ${WRKSRC}/docs/_build/man/translatetoolkit.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
		${RM} -rf ${WRKSRC}/docs
		${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/translate/docs/

.endif
