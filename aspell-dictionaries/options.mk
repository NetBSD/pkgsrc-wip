# $NetBSD: options.mk,v 1.2 2012/11/11 22:00:03 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aspell-dictionaries
PKG_SUPPORTED_OPTIONS=	lang-br lang-ca lang-cs lang-cy lang-da lang-de lang-el
PKG_SUPPORTED_OPTIONS+= lang-en lang-eo lang-es lang-fi lang-fo lang-fr lang-ga
PKG_SUPPORTED_OPTIONS+= lang-it lang-nb lang-nl lang-pl lang-pt lang-ro lang-ru
PKG_SUPPORTED_OPTIONS+= lang-sk lang-sv lang-te lang-uk
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-br)
DEPENDS+=	aspell-breton>=0.50.2:../../textproc/aspell-breton
.endif

.if !empty(PKG_OPTIONS:Mlang-ca)
DEPENDS+=	aspell-catalan>=20040130.1:../../textproc/aspell-catalan
.endif

.if !empty(PKG_OPTIONS:Mlang-cs)
DEPENDS+=	aspell-czech>=20040614.1:../../textproc/aspell-czech
.endif

.if !empty(PKG_OPTIONS:Mlang-cy)
DEPENDS+=	aspell-welsh>=0.50.3:../../textproc/aspell-welsh
.endif

.if !empty(PKG_OPTIONS:Mlang-da)
DEPENDS+=	aspell-danish>=1.4.52:../../textproc/aspell-danish
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DEPENDS+=	aspell-german>=20030222.1:../../textproc/aspell-german
.endif

.if !empty(PKG_OPTIONS:Mlang-el)
DEPENDS+=	aspell-greek>=0.50.3:../../textproc/aspell-greek
.endif

.if !empty(PKG_OPTIONS:Mlang-en)
DEPENDS+=	aspell-english>=6.0.0:../../textproc/aspell-english
.endif

.if !empty(PKG_OPTIONS:Mlang-eo)
DEPENDS+=	aspell-esperanto>=0.50.2:../../textproc/aspell-esperanto
.endif

.if !empty(PKG_OPTIONS:Mlang-es)
DEPENDS+=	aspell-spanish>=0.50.2:../../textproc/aspell-spanish
.endif

.if !empty(PKG_OPTIONS:Mlang-fi)
DEPENDS+=	aspell-finnish>=0.7.0:../../wip/aspell-finnish
.endif

.if !empty(PKG_OPTIONS:Mlang-fo)
DEPENDS+=	aspell-faroese>=0.2.24:../../textproc/aspell-faroese
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DEPENDS+=	aspell-francais>=0.50.3:../../textproc/aspell-francais
.endif

.if !empty(PKG_OPTIONS:Mlang-ga)
DEPENDS+=	aspell-gaeilge>=3.5.0:../../textproc/aspell-gaeilge
.endif

.if !empty(PKG_OPTIONS:Mlang-it)
DEPENDS+=	aspell-italian>=0.53.0:../../textproc/aspell-italian
.endif

.if !empty(PKG_OPTIONS:Mlang-nb)
DEPENDS+=	aspell-norwegian>=0.50.1.0:../../textproc/aspell-norwegian
.endif

.if !empty(PKG_OPTIONS:Mlang-nl)
DEPENDS+=	aspell-dutch>=0.50.2:../../textproc/aspell-dutch
.endif

.if !empty(PKG_OPTIONS:Mlang-pl)
DEPENDS+=	aspell-polish>=0.51.0:../../textproc/aspell-polish
.endif

.if !empty(PKG_OPTIONS:Mlang-pt)
DEPENDS+=	aspell-portuguese>=0.50.2:../../textproc/aspell-portuguese
.endif

.if !empty(PKG_OPTIONS:Mlang-ro)
DEPENDS+=	aspell-romanian>=0.50.2:../../textproc/aspell-romanian
.endif

.if !empty(PKG_OPTIONS:Mlang-ru)
DEPENDS+=	aspell-russian>=0.99f7.1:../../textproc/aspell-russian
.endif

.if !empty(PKG_OPTIONS:Mlang-sk)
DEPENDS+=	aspell-slovak>=0.52.0:../../textproc/aspell-slovak
.endif

.if !empty(PKG_OPTIONS:Mlang-sv)
DEPENDS+=	aspell-svenska>=0.51.0:../../textproc/aspell-svenska
.endif

.if !empty(PKG_OPTIONS:Mlang-te)
DEPENDS+=	aspell-telugu>=0.01.2:../../wip/aspell-telugu
.endif

.if !empty(PKG_OPTIONS:Mlang-uk)
DEPENDS+=	aspell-ukrainian>=1.1.0:../../textproc/aspell-ukrainian
.endif
