############################################################

PREFIX?=/usr/local
BINDIR?=${PREFIX}/bin
MANDIR?=${PREFIX}/man

INST_DIR?=	${INSTALL} -d

############################################################

.include "Makefile.version"

SCRIPTS=	pkg_cmp_summary pkg_list_all_pkgs
SCRIPTS+=	pkg_refresh_summary pkg_src_fetch_var
SCRIPTS+=	pkg_micro_src_summary pkg_src_summary
SCRIPTS+=	pkg_update_src_summary pkg_summary4view
SCRIPTS+=	pkg_update_summary

MAN=		pkg_cmp_summary.1 pkg_micro_src_summary.1
MAN+=		pkg_src_summary.1 pkg_update_src_summary.1
MAN+=		pkg_summary4view.1 pkg_update_summary.1

BIRTHDAY=	2008-04-06

PROJECTNAME=	pkg_summary-utils

############################################################
.PHONY: install-dirs
install-dirs:
	$(INST_DIR) ${DESTDIR}${BINDIR}
.if "$(MKMAN)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/man1
.if "$(MKCATPAGES)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/cat1
.endif
.endif

############################################################

.sinclude "Makefile.cvsdist"

.include <bsd.prog.mk>
