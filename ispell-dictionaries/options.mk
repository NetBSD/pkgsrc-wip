# $NetBSD: options.mk,v 1.2 2012/11/11 22:16:16 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ispell-dictionaries
PKG_SUPPORTED_OPTIONS=	lang-ca lang-de lang-en-gb lang-es lang-fr lang-ga
PKG_SUPPORTED_OPTIONS+= lang-lt lang-pl lang-ro lang-ru lang-ru-io lang-sk
PKG_SUPPORTED_OPTIONS+=	lang-sv
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-ca)
DEPENDS+=	ispell-catalan>=1.0:../../textproc/ispell-catalan
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DEPENDS+=	ispell-german>=20081106:../../textproc/ispell-german
.endif

.if !empty(PKG_OPTIONS:Mlang-en-gb)
DEPENDS+=	ispell-british>=3.3.02:../../textproc/ispell-british
.endif

.if !empty(PKG_OPTIONS:Mlang-es)
DEPENDS+=	ispell-spanish>=1.7:../../textproc/ispell-spanish
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DEPENDS+=	ispell-francais>=1.4:../../textproc/ispell-francais
.endif

.if !empty(PKG_OPTIONS:Mlang-ga)
DEPENDS+=	ispell-gaeilge>=2.0:../../textproc/ispell-gaeilge
.endif

.if !empty(PKG_OPTIONS:Mlang-lt)
DEPENDS+=	ispell-lietuviu>=1.0:../../wip/ispell-lietuviu
.endif

.if !empty(PKG_OPTIONS:Mlang-pl)
DEPENDS+=	ispell-polski>=20021127:../../textproc/ispell-polski
.endif

.if !empty(PKG_OPTIONS:Mlang-ro)
DEPENDS+=	ispell-romanian>=20031216:../../textproc/ispell-romanian
.endif

.if !empty(PKG_OPTIONS:Mlang-ru)
DEPENDS+=	ispell-russian>=0.99g4:../../textproc/ispell-russian
.endif

.if !empty(PKG_OPTIONS:Mlang-ru-io)
DEPENDS+=	ispell-russian-io>=0.99g4:../../textproc/ispell-russian-io
.endif

.if !empty(PKG_OPTIONS:Mlang-sk)
DEPENDS+=	ispell-slovak>=0.2.2:../../textproc/ispell-slovak
.endif

.if !empty(PKG_OPTIONS:Mlang-sv)
DEPENDS+=	ispell-svenska>=1.2.1:../../textproc/ispell-svenska
.endif
