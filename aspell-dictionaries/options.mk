# $NetBSD: options.mk,v 1.1.1.1 2009/11/15 02:23:32 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aspell-dictionaries
PKG_SUPPORTED_OPTIONS=	breton catalan czech danish dutch english esperanto
PKG_SUPPORTED_OPTIONS+= faroese finnish francais gaeilge german greek italian
PKG_SUPPORTED_OPTIONS+= norwegian polish portuguese romanian russian slovak
PKG_SUPPORTED_OPTIONS+= spanish svenska telugu ukrainian welsh
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbreton)
DEPENDS+=	aspell-breton>=0.50.2:../../textproc/aspell-breton
.endif

.if !empty(PKG_OPTIONS:Mcatalan)
DEPENDS+=	aspell-catalan>=20040130.1:../../textproc/aspell-catalan
.endif

.if !empty(PKG_OPTIONS:Mczech)
DEPENDS+=	aspell-czech>=20040614.1:../../textproc/aspell-czech
.endif

.if !empty(PKG_OPTIONS:Mdanish)
DEPENDS+=	aspell-danish>=1.4.52:../../textproc/aspell-danish
.endif

.if !empty(PKG_OPTIONS:Mdutch)
DEPENDS+=	aspell-dutch>=0.50.2:../../textproc/aspell-dutch
.endif

.if !empty(PKG_OPTIONS:Menglish)
DEPENDS+=	aspell-english>=6.0.0:../../textproc/aspell-english
.endif

.if !empty(PKG_OPTIONS:Mesperanto)
DEPENDS+=	aspell-esperanto>=0.50.2:../../textproc/aspell-esperanto
.endif

.if !empty(PKG_OPTIONS:Mfaroese)
DEPENDS+=	aspell-faroese>=0.2.24:../../textproc/aspell-faroese
.endif

.if !empty(PKG_OPTIONS:Mfinnish)
DEPENDS+=	aspell-finnish>=0.7.0:../../wip/aspell-finnish
.endif

.if !empty(PKG_OPTIONS:Mfrancais)
DEPENDS+=	aspell-francais>=0.50.3:../../textproc/aspell-francais
.endif

.if !empty(PKG_OPTIONS:Mgaeilge)
DEPENDS+=	aspell-gaeilge>=3.5.0:../../textproc/aspell-gaeilge
.endif

.if !empty(PKG_OPTIONS:Mgerman)
DEPENDS+=	aspell-german>=20030222.1:../../textproc/aspell-german
.endif

.if !empty(PKG_OPTIONS:Mgreek)
DEPENDS+=	aspell-greek>=0.50.3:../../textproc/aspell-greek
.endif

.if !empty(PKG_OPTIONS:Mitalian)
DEPENDS+=	aspell-italian>=0.53.0:../../textproc/aspell-italian
.endif

.if !empty(PKG_OPTIONS:Mnorwegian)
DEPENDS+=	aspell-norwegian>=0.50.1.0:../../textproc/aspell-norwegian
.endif

.if !empty(PKG_OPTIONS:Mpolish)
DEPENDS+=	aspell-polish>=0.51.0:../../textproc/aspell-polish
.endif

.if !empty(PKG_OPTIONS:Mportuguese)
DEPENDS+=	aspell-portuguese>=0.50.2:../../textproc/aspell-portuguese
.endif

.if !empty(PKG_OPTIONS:Mromanian)
DEPENDS+=	aspell-romanian>=0.50.2:../../textproc/aspell-romanian
.endif

.if !empty(PKG_OPTIONS:Mrussian)
DEPENDS+=	aspell-russian>=0.99f7.1:../../textproc/aspell-russian
.endif

.if !empty(PKG_OPTIONS:Mslovak)
DEPENDS+=	aspell-slovak>=0.52.0:../../textproc/aspell-slovak
.endif

.if !empty(PKG_OPTIONS:Mspanish)
DEPENDS+=	aspell-spanish>=0.50.2:../../textproc/aspell-spanish
.endif

.if !empty(PKG_OPTIONS:Msvenska)
DEPENDS+=	aspell-svenska>=0.51.0:../../textproc/aspell-svenska
.endif

.if !empty(PKG_OPTIONS:Mtelugu)
DEPENDS+=	aspell-telugu>=0.01.2:../../wip/aspell-telugu
.endif

.if !empty(PKG_OPTIONS:Mukrainian)
DEPENDS+=	aspell-ukrainian>=1.1.0:../../textproc/aspell-ukrainian
.endif

.if !empty(PKG_OPTIONS:Mwelsh)
DEPENDS+=	aspell-welsh>=0.50.3:../../textproc/aspell-welsh
.endif
