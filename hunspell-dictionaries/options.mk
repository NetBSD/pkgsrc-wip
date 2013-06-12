# $NetBSD: options.mk,v 1.1 2013/06/12 11:36:35 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hunspell-dictionaries
PKG_SUPPORTED_OPTIONS=	lang-af lang-ar lang-bg lang-ca lang-cs lang-cy lang-da
PKG_SUPPORTED_OPTIONS+=	lang-de lang-el lang-en-ca lang-en-gb lang-en-nz
PKG_SUPPORTED_OPTIONS+=	lang-en-us lang-en-za lang-es lang-es-mx lang-fo
PKG_SUPPORTED_OPTIONS+=	lang-fr lang-fy lang-ga lang-he lang-hr lang-hu lang-id
PKG_SUPPORTED_OPTIONS+=	lang-it lang-lt lang-lv lang-mg lang-ms lang-nl
PKG_SUPPORTED_OPTIONS+=	lang-ny lang-pl lang-ru lang-sk lang-sv lang-uk
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-af)
DEPENDS+=	hunspell-af_ZA>=20060117:../../textproc/hunspell-af_ZA
.endif

.if !empty(PKG_OPTIONS:Mlang-ar)
DEPENDS+=	hunspell-ar>=20080110:../../textproc/hunspell-ar
.endif

.if !empty(PKG_OPTIONS:Mlang-bg)
DEPENDS+=	hunspell-bg_BG>=20040405:../../textproc/hunspell-bg_BG
.endif

.if !empty(PKG_OPTIONS:Mlang-ca)
DEPENDS+=	hunspell-ca_ES>=20080427:../../textproc/hunspell-ca_ES
.endif

.if !empty(PKG_OPTIONS:Mlang-cs)
DEPENDS+=	hunspell-cs_CZ>=20061030:../../textproc/hunspell-cs_CZ
.endif

.if !empty(PKG_OPTIONS:Mlang-cy)
DEPENDS+=	hunspell-cy_GB>=20040425:../../textproc/hunspell-cy_GB
.endif

.if !empty(PKG_OPTIONS:Mlang-da)
DEPENDS+=	hunspell-da_DK>=20070106:../../textproc/hunspell-da_DK
.endif

.if !empty(PKG_OPTIONS:Mlang-de)
DEPENDS+=	hunspell-de>=20120607nb1:../../textproc/hunspell-de
.endif

.if !empty(PKG_OPTIONS:Mlang-el)
DEPENDS+=	hunspell-el_GR>=20041220:../../textproc/hunspell-el_GR
.endif

.if !empty(PKG_OPTIONS:Mlang-en-ca)
DEPENDS+=	hunspell-en_CA>=20020315:../../textproc/hunspell-en_CA
.endif

.if !empty(PKG_OPTIONS:Mlang-en-gb)
DEPENDS+=	hunspell-en_GB>=20061130:../../textproc/hunspell-en_GB
.endif

.if !empty(PKG_OPTIONS:Mlang-en-nz)
DEPENDS+=	hunspell-en_NZ>=20020518:../../textproc/hunspell-en_NZ
.endif

.if !empty(PKG_OPTIONS:Mlang-en-us)
DEPENDS+=	hunspell-en_US>=20060207:../../textproc/hunspell-en_US
.endif

.if !empty(PKG_OPTIONS:Mlang-en-za)
DEPENDS+=	hunspell-en_ZA>=20060120:../../textproc/hunspell-en_ZA
.endif

.if !empty(PKG_OPTIONS:Mlang-es)
DEPENDS+=	hunspell-es_ES>=20050510:../../textproc/hunspell-es_ES
.endif

.if !empty(PKG_OPTIONS:Mlang-es-mx)
DEPENDS+=	hunspell-es_MX>=20050505:../../textproc/hunspell-es_MX
.endif

.if !empty(PKG_OPTIONS:Mlang-fo)
DEPENDS+=	hunspell-fo_FO>=20050307:../../textproc/hunspell-fo_FO
.endif

.if !empty(PKG_OPTIONS:Mlang-fr)
DEPENDS+=	hunspell-fr_FR>=2.3.2:../../textproc/hunspell-fr_FR
.endif

.if !empty(PKG_OPTIONS:Mlang-fy)
DEPENDS+=	hunspell-fy_NL>=0.12:../../textproc/hunspell-fy_NL
.endif

.if !empty(PKG_OPTIONS:Mlang-ga)
DEPENDS+=	hunspell-ga_IE>=20071029:../../textproc/hunspell-ga_IE
.endif

.if !empty(PKG_OPTIONS:Mlang-he)
DEPENDS+=	hunspell-he_IL>=20050112:../../textproc/hunspell-he_IL
.endif

.if !empty(PKG_OPTIONS:Mlang-hr)
DEPENDS+=	hunspell-hr_HR>=20060607:../../textproc/hunspell-hr_HR
.endif

.if !empty(PKG_OPTIONS:Mlang-hu)
DEPENDS+=	hunspell-hu_HU>=1.6.1:../../textproc/hunspell-hu_HU
.endif

.if !empty(PKG_OPTIONS:Mlang-id)
DEPENDS+=	hunspell-id_ID>=20040410:../../textproc/hunspell-id_ID
.endif

.if !empty(PKG_OPTIONS:Mlang-it)
DEPENDS+=	hunspell-it_IT>=2.4:../../textproc/hunspell-it_IT
.endif

.if !empty(PKG_OPTIONS:Mlang-lt)
DEPENDS+=	hunspell-lt_LT>=20031231:../../textproc/hunspell-lt_LT
.endif

.if !empty(PKG_OPTIONS:Mlang-lv)
DEPENDS+=	hunspell-lv_LV>=0.8:../../textproc/hunspell-lv_LV
.endif

.if !empty(PKG_OPTIONS:Mlang-mg)
DEPENDS+=	hunspell-mg_MG>=20050108:../../textproc/hunspell-mg_MG
.endif

.if !empty(PKG_OPTIONS:Mlang-ms)
DEPENDS+=	hunspell-ms_MY>=20050117:../../textproc/hunspell-ms_MY
.endif

.if !empty(PKG_OPTIONS:Mlang-nl)
DEPENDS+=	hunspell-nl_NL>=20070607:../../textproc/hunspell-nl_NL
.endif

.if !empty(PKG_OPTIONS:Mlang-ny)
DEPENDS+=	hunspell-ny_MW>=20050108:../../textproc/hunspell-ny_MW
.endif

.if !empty(PKG_OPTIONS:Mlang-pl)
DEPENDS+=	hunspell-pl_PL>=20061202:../../textproc/hunspell-pl_PL
.endif

.if !empty(PKG_OPTIONS:Mlang-ru)
DEPENDS+=	hunspell-ru_RU>=20040406:../../textproc/hunspell-ru_RU
.endif

.if !empty(PKG_OPTIONS:Mlang-sk)
DEPENDS+=	hunspell-sk_SK>=20090330:../../textproc/hunspell-sk_SK
.endif

.if !empty(PKG_OPTIONS:Mlang-sv)
DEPENDS+=	hunspell-sv_SE>=1.27:../../textproc/hunspell-sv_SE
.endif

.if !empty(PKG_OPTIONS:Mlang-uk)
DEPENDS+=	hunspell-uk_UA>=20090125:../../wip/hunspell-uk_UA
.endif
