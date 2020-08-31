# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.translate-toolkit
PKG_SUPPORTED_OPTIONS+=		lxml levenshtein chardet tradostm pycountry doc ical ini csv
PKG_SUGGESTED_OPTIONS=		lxml levenshtein chardet tradostm pycountry ical ini 
PLIST_VARS=			csv doc


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlxml)
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5:../../textproc/py-lxml
.endif

.if !empty(PKG_OPTIONS:Mlevenshtein)
DEPENDS+=	${PYPKGPREFIX}-Levenshtein>=0.12:../../textproc/py-Levenshtein
.endif

.if !empty(PKG_OPTIONS:Mchardet)
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet
.endif

.if !empty(PKG_OPTIONS:Mpycountry)
DEPENDS+=	${PYPKGPREFIX}-country>=1.10:../../geography/py-country
.endif

.if !empty(PKG_OPTIONS:Mtradostm)
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3:../../www/py-beautifulsoup4
.endif

.if !empty(PKG_OPTIONS:Mical)
DEPENDS+=	${PYPKGPREFIX}-vobject>=0.9.6:../../textproc/py-vobject
.endif

.if !empty(PKG_OPTIONS:Mini)
.  if empty(_PYTHON_VERSION:M3*)
DEPENDS+=	${PYPKGPREFIX}-iniparse>=0.4:../../textproc/py-iniparse
.  endif
.endif

.if !empty(PKG_OPTIONS:Mcsv)
.  if empty(_PYTHON_VERSION:M3*)
DEPENDS+=	${PYPKGPREFIX}-backports.csv>=1.0.6:../../wip/py-backports.csv
PLIST.csv=	yes
.  endif
.endif

#Off till someone updates textproc/py-sphinx to 3.1.1
.if !empty(PKG_OPTIONS:Mdoc)
PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx>=3.1.1.:../../textproc/py-sphinx
SUBST_CLASSES+=		sphinx
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},"
SUBST_FILES.sphinx+=	docs/Makefile
SUBST_STAGE.sphinx=	pre-configure
SUBST_MESSAGE.sphinx=	Fix sphinx command names.
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
PLIST.doc=		yes

pre-build:
	cd ${WRKSRC}/docs && ${MAKE} man
pre-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/translatetoolkit.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -rf ${WRKSRC}/docs
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/translate/docs/

.endif
