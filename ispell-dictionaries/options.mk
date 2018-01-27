# $NetBSD: options.mk,v 1.5 2013/06/02 07:35:59 kristerw Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ispell-dictionaries
PKG_SUPPORTED_OPTIONS=	lang-ca lang-de lang-en-gb lang-es lang-fr lang-ga
PKG_SUPPORTED_OPTIONS+=	lang-lt lang-pl lang-ro lang-ru lang-ru-io lang-sk
PKG_SUPPORTED_OPTIONS+=	lang-sv
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-ca)
DEPENDS+=	ispell-ca>=1.0:../../textproc/ispell-ca
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DEPENDS+=	ispell-de>=20081106:../../textproc/ispell-de
.endif

.if !empty(PKG_OPTIONS:Mlang-en-gb)
DEPENDS+=	ispell-british>=3.3.02:../../textproc/ispell-en_GB
.endif

.if !empty(PKG_OPTIONS:Mlang-es)
DEPENDS+=	ispell-es>=1.7:../../textproc/ispell-es
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DEPENDS+=	ispell-fr>=1.4:../../textproc/ispell-fr
.endif

.if !empty(PKG_OPTIONS:Mlang-ga)
DEPENDS+=	ispell-ga>=2.0:../../textproc/ispell-ga
.endif

.if !empty(PKG_OPTIONS:Mlang-lt)
DEPENDS+=	ispell-lt>=1.0:../../textproc/ispell-lt
.endif

.if !empty(PKG_OPTIONS:Mlang-pl)
DEPENDS+=	ispell-pl>=20021127:../../textproc/ispell-pl
.endif

.if !empty(PKG_OPTIONS:Mlang-ro)
DEPENDS+=	ispell-ro>=20031216:../../textproc/ispell-ro
.endif

.if !empty(PKG_OPTIONS:Mlang-ru)
DEPENDS+=	ispell-ru>=0.99g4:../../textproc/ispell-ru
.endif

.if !empty(PKG_OPTIONS:Mlang-ru-io)
DEPENDS+=	ispell-ru-io>=0.99g4:../../textproc/ispell-ru-io
.endif

.if !empty(PKG_OPTIONS:Mlang-sk)
DEPENDS+=	ispell-sk>=0.2.2:../../textproc/ispell-sk
.endif

.if !empty(PKG_OPTIONS:Mlang-sv)
DEPENDS+=	ispell-sv>=1.2.1:../../textproc/ispell-sv
.endif
