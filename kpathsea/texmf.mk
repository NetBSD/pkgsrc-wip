# $NetBSD: texmf.mk,v 1.1 2008/12/13 08:53:05 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX packages.  It rebuilds the ls-R databases at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_TEXMF_DIRS - A list of texmf directories that need to update ls-R.
#                     Default: ${PREFIX}/share/texmf-dist
#

.if !defined(TEX_TEXMF_MK)
TEX_TEXMF_MK=		# defined

DEPENDS+=		kpathsea>=3.5.7:../../wip/kpathsea

TEX_TEXMF_DIRS?=	${PREFIX}/share/texmf-dist
EVAL_PREFIX+=		KPATHSEA_PREFIX=kpathsea
FILES_SUBST+=		MKTEXLSR=${KPATHSEA_PREFIX:Q}/bin/mktexlsr
FILES_SUBST+=		TEXMF_DIRS=${TEX_TEXMF_DIRS:Q}
INSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-install.tmpl
DEINSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-deinstall.tmpl

.endif	# TEX_TEXMF_MK
