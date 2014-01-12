# $NetBSD: options.mk,v 1.2 2014/01/12 21:07:14 cheusov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.texlive
PKG_OPTIONS_REQUIRED_GROUPS=	texmf
PKG_OPTIONS_GROUP.texmf=	texmf-minimal texmf-full
PKG_SUPPORTED_OPTIONS=		texmf-doc
PKG_SUGGESTED_OPTIONS=		texmf-minimal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtexmf-full)
DEPENDS+=	texlive-texmf-full-[0-9]*:../../wip/texlive-texmf-full
.endif

.if !empty(PKG_OPTIONS:Mtexmf-minimal)
DEPENDS+=	texlive-texmf-minimal-[0-9]*:../../wip/texlive-texmf-minimal
.endif

#
# texmf-doc can be installed independently of the minimal/full texmf set
# I guess this means there's no matching doc package for the minimal texmf set
#
.if !empty(PKG_OPTIONS:Mtexmf-doc)
DEPENDS+=	texlive-texmf-doc-[0-9]*:../../wip/texlive-texmf-doc
.endif
