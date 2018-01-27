# $NetBSD: options.mk,v 1.3 2013/04/10 00:28:36 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aspell-dictionaries
PKG_SUPPORTED_OPTIONS=	lang-br lang-ca lang-cs lang-cy lang-da lang-de lang-el
PKG_SUPPORTED_OPTIONS+=	lang-en lang-eo lang-es lang-fi lang-fo lang-fr lang-ga
PKG_SUPPORTED_OPTIONS+=	lang-it lang-nb lang-nl lang-pl lang-pt lang-ro lang-ru
PKG_SUPPORTED_OPTIONS+=	lang-sk lang-sv lang-te lang-uk
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-br)
DEPENDS+=	aspell-br>=0.50.2:../../textproc/aspell-br
.endif

.if !empty(PKG_OPTIONS:Mlang-ca)
DEPENDS+=	aspell-ca>=2.1.5.1:../../textproc/aspell-ca
.endif

.if !empty(PKG_OPTIONS:Mlang-cs)
DEPENDS+=	aspell-cs>=20040614.1:../../textproc/aspell-cs
.endif

.if !empty(PKG_OPTIONS:Mlang-cy)
DEPENDS+=	aspell-cy>=0.50.3:../../textproc/aspell-cy
.endif

.if !empty(PKG_OPTIONS:Mlang-da)
DEPENDS+=	aspell-da>=1.4.52:../../textproc/aspell-da
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DEPENDS+=	aspell-de>=20030222.1:../../textproc/aspell-de
.endif

.if !empty(PKG_OPTIONS:Mlang-el)
DEPENDS+=	aspell-el>=0.50.3:../../textproc/aspell-el
.endif

.if !empty(PKG_OPTIONS:Mlang-en)
DEPENDS+=	aspell-en>=6.0.0:../../textproc/aspell-en
.endif

.if !empty(PKG_OPTIONS:Mlang-eo)
DEPENDS+=	aspell-eo>=0.50.2:../../textproc/aspell-eo
.endif

.if !empty(PKG_OPTIONS:Mlang-es)
DEPENDS+=	aspell-es>=0.50.2:../../textproc/aspell-es
.endif

.if !empty(PKG_OPTIONS:Mlang-fi)
DEPENDS+=	aspell-fi>=0.7.0:../../textproc/aspell-fi
.endif

.if !empty(PKG_OPTIONS:Mlang-fo)
DEPENDS+=	aspell-fo>=0.2.24:../../textproc/aspell-fo
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DEPENDS+=	aspell-fr>=0.50.3:../../textproc/aspell-fr
.endif

.if !empty(PKG_OPTIONS:Mlang-ga)
DEPENDS+=	aspell-ga>=3.5.0:../../textproc/aspell-ga
.endif

.if !empty(PKG_OPTIONS:Mlang-it)
DEPENDS+=	aspell-it>=0.53.0:../../textproc/aspell-it
.endif

.if !empty(PKG_OPTIONS:Mlang-nb)
DEPENDS+=	aspell-nb>=0.50.1.0:../../textproc/aspell-nb
.endif

.if !empty(PKG_OPTIONS:Mlang-nl)
DEPENDS+=	aspell-nl>=0.50.2:../../textproc/aspell-nl
.endif

.if !empty(PKG_OPTIONS:Mlang-pl)
DEPENDS+=	aspell-pl>=0.51.0:../../textproc/aspell-pl
.endif

.if !empty(PKG_OPTIONS:Mlang-pt)
DEPENDS+=	aspell-pt_PT>=0.50.2:../../textproc/aspell-pt_PT
.endif

.if !empty(PKG_OPTIONS:Mlang-ro)
DEPENDS+=	aspell-ro>=0.50.2:../../textproc/aspell-ro
.endif

.if !empty(PKG_OPTIONS:Mlang-ru)
DEPENDS+=	aspell-ru>=0.99f7.1:../../textproc/aspell-ru
.endif

.if !empty(PKG_OPTIONS:Mlang-sk)
DEPENDS+=	aspell-sk>=0.52.0:../../textproc/aspell-sk
.endif

.if !empty(PKG_OPTIONS:Mlang-sv)
DEPENDS+=	aspell-sv>=0.51.0:../../textproc/aspell-sv
.endif

.if !empty(PKG_OPTIONS:Mlang-te)
DEPENDS+=	aspell-te>=0.01.2:../../textproc/aspell-te
.endif

.if !empty(PKG_OPTIONS:Mlang-uk)
DEPENDS+=	aspell-uk>=1.1.0:../../textproc/aspell-uk
.endif
