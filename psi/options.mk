# $NetBSD: options.mk,v 1.2 2012/12/07 23:52:09 schnoebe Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.psi
PKG_SUPPORTED_OPTIONS+=	hunspell enchant
PKG_SUGGESTED_OPTIONS+=	enchant

# from an idea stolen from ../../misc/openoffice3.
PSI_SUPPORTED_LANGUAGES=be cs de eo es es-es fr it ja mk pl pt-br ru \
			sl sv uk ur-pk vi zh-cn zh-tw

.for l in ${PSI_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+= lang-${l}
PLIST_VARS+=${l}
.endfor

.include "../../mk/bsd.options.mk"

# handle the languages first
#   bit of special logic, as the dialects of languages are handled
#   as lang_DIALECT (aka, lower underscore UPPER) in the PSI translations
.for lang in ${PKG_OPTIONS:Mlang-*:S/lang-//g}
PLIST.${lang} = yes
. if ${lang:M??-??}
    LANG_FILES+= psi_${lang:C/-.*//g}_${lang:C/.*-//g:tu}.qm
. else
    LANG_FILES+= psi_${lang}.qm
. endif
.endfor

# enable hunspell
.if !empty(PKG_OPTIONS:Mhunspell)
CMAKE_ARGS+=	-DUSE_HUNSPELL:BOOL=TRUE
.include "../../textproc/hunspell/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_HUNSPELL:BOOL=FALSE
.endif

# enable enchant
.if !empty(PKG_OPTIONS:Menchant)
CMAKE_ARGS+=	-DUSE_ENCHANT:BOOL=TRUE
.include "../../textproc/enchant2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_ENCHANT:BOOL=FALSE
.endif
