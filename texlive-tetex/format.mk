# $NetBSD: format.mk,v 1.2 2009/01/05 19:00:23 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX format files.  It creates format files at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_FORMAT_NAMES - A list of format names.
#

.if !defined(TEX_FORMAT_MK)
TEX_FORMAT_MK=		# defined

DEPENDS+=		texlive-tetex>=2008:../../wip/texlive-tetex
DEPENDS+=		tex-bin-texlive-[0-9]*:../../wip/tex-bin-texlive

EVAL_PREFIX+=		TETEX_PREFIX=texlive-tetex
FILES_SUBST+=		FMTUTIL_SYS=${TETEX_PREFIX:Q}/bin/fmtutil-sys
FILES_SUBST+=		FORMAT_NAMES=${TEX_FORMAT_NAMES:Q}
INSTALL_TEMPLATES+=	../../wip/texlive-tetex/files/format-install.tmpl
DEINSTALL_TEMPLATES+=	../../wip/texlive-tetex/files/format-deinstall.tmpl

.endif	# TEX_FORMAT_MK
