############################################################

PREFIX?=/usr/local
BINDIR?=${PREFIX}/bin
MANDIR?=${PREFIX}/man

INST_DIR?=	${INSTALL} -d

############################################################

.include "Makefile.version"

SCRIPTS=	pkg_update_summary pkg_refresh_summary
MAN=		pkg_update_summary.1

BIRTHDAY=	2007-06-17

PROJECTNAME=	pkg_update_summary

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
