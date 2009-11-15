# $NetBSD: options.mk,v 1.1.1.1 2009/11/15 02:45:26 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ispell-dictionaries
PKG_SUPPORTED_OPTIONS=	british catalan francais gaeilge german lietuviu polski
PKG_SUPPORTED_OPTIONS+= romanian russian russian-io slovak spanish svenska
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbritish)
DEPENDS+=	ispell-british>=3.3.02:../../textproc/ispell-british
.endif

.if !empty(PKG_OPTIONS:Mcatalan)
DEPENDS+=	ispell-catalan>=1.0:../../textproc/ispell-catalan
.endif

.if !empty(PKG_OPTIONS:Mfrancais)
DEPENDS+=	ispell-francais>=1.4:../../textproc/ispell-francais
.endif

.if !empty(PKG_OPTIONS:Mgaeilge)
DEPENDS+=	ispell-gaeilge>=2.0:../../textproc/ispell-gaeilge
.endif

.if !empty(PKG_OPTIONS:Mgerman)
DEPENDS+=	ispell-german>=20081106:../../textproc/ispell-german
.endif

.if !empty(PKG_OPTIONS:Mlietuviu)
DEPENDS+=	ispell-lietuviu>=1.0:../../wip/ispell-lietuviu
.endif

.if !empty(PKG_OPTIONS:Mpolski)
DEPENDS+=	ispell-polski>=20021127:../../textproc/ispell-polski
.endif

.if !empty(PKG_OPTIONS:Mromanian)
DEPENDS+=	ispell-romanian>=20031216:../../textproc/ispell-romanian
.endif

.if !empty(PKG_OPTIONS:Mrussian)
DEPENDS+=	ispell-russian>=0.99g4:../../textproc/ispell-russian
.endif

.if !empty(PKG_OPTIONS:Mrussian-io)
DEPENDS+=	ispell-russian-io>=0.99g4:../../textproc/ispell-russian-io
.endif

.if !empty(PKG_OPTIONS:Mslovak)
DEPENDS+=	ispell-slovak>=0.2.2:../../textproc/ispell-slovak
.endif

.if !empty(PKG_OPTIONS:Mspanish)
DEPENDS+=	ispell-spanish>=1.7:../../textproc/ispell-spanish
.endif

.if !empty(PKG_OPTIONS:Msvenska)
DEPENDS+=	ispell-svenska>=1.2.1:../../textproc/ispell-svenska
.endif
